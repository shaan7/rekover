/***************************************************************************
 *   Rekover is a tool for your N9/N950 to track it if stolen              *
 *                                                                         *
 *   Copyright 2012 by Shantanu Tushar <shantanu@kde.org>                  *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#include "textmessagecommandsource.h"

#include <QtCore/QString>
#include <QtCore/QTimer>

#include <QDebug>

TextMessageCommandSource::TextMessageCommandSource(QObject *parent) :
    AbstractCommandSource(parent),
    m_incident(0)
{
    qDebug() << "PREPARING...";
    m_messageManager.registerNotificationFilter(QMessageFilter::byType(QMessage::Sms) &
                                                QMessageFilter::byStandardFolder(QMessage::InboxFolder));
    connect(&m_messageManager, SIGNAL(messageAdded(QMessageId,QMessageManager::NotificationFilterIdSet)),
            SLOT(processNewMessage(QMessageId,QMessageManager::NotificationFilterIdSet)));
    qDebug() << "DONE, LISTENING ...";
}

void TextMessageCommandSource::sendResponseImpl(const QString &response, const QString &incidentId)
{
    qDebug() << "OUT " << incidentId.toInt() << response;
    QMessage message;
    if (m_addressesByIncident.contains(incidentId.toInt())) {
        message.setType(QMessage::Sms);
        message.setTo(m_addressesByIncident.value(incidentId.toInt()));
        message.setBody(response);

        m_messageService.send(message);
    } else {
        qDebug() << "WARNING, Incident Id " << incidentId << "not found";
    }
}

void TextMessageCommandSource::processNewMessage(QMessageId id,QMessageManager::NotificationFilterIdSet set)
{
    qDebug() << "GOT MESSAGE ID " << id.toString();
    QMessage message = m_messageManager.message(id);
    QMessageContentContainer messageBody = message.find(message.bodyId());

    m_addressesByIncident.insert(m_incident, message.from());
    emit newCommand(messageBody.textContent(), QString::number(m_incident++));
}
