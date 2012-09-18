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

#include "abstractcommand.h"

#include "abstractcommandsource.h"

AbstractCommand::AbstractCommand(QObject *parent) :
    QObject(parent)
{
}

void AbstractCommand::processCommand(const QStringList &commandLine, AbstractCommandSource *commandSource, const QString &incidentId)
{
    m_incidentId = incidentId;
    m_commandSource = commandSource;
    processCommandImpl(commandLine);
}

QString AbstractCommand::incidentId() const
{
    return m_incidentId;
}

void AbstractCommand::sendResponse(const QString &response)
{
    m_commandSource->sendResponse(response, m_incidentId);
}
