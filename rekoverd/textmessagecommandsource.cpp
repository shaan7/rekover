#include "textmessagecommandsource.h"

#include <QtCore/QString>
#include <QtCore/QTimer>

#include <QDebug>

TextMessageCommandSource::TextMessageCommandSource(QObject *parent) :
    AbstractCommandSource(parent)
{
    qDebug() << "PREPARING...";
    m_messageManager.registerNotificationFilter(QMessageFilter::byType(QMessage::AnyType));
    connect(&m_messageManager, SIGNAL(messageAdded(QMessageId,QMessageManager::NotificationFilterIdSet)),
            SLOT(processNewMessage(QMessageId,QMessageManager::NotificationFilterIdSet)));
    qDebug() << "DONE, LISTENING ...";
}

void TextMessageCommandSource::sendResponseImpl(const QString &response)
{
    qDebug() << "OUT " << response;
}

void TextMessageCommandSource::processNewMessage(QMessageId id,QMessageManager::NotificationFilterIdSet set)
{
    QMessage message = m_messageManager.message(id);
    qDebug() << "GOT MESSAGE ID " << id.toString();
    qDebug() << "MESSAGE IS " << message.find(message.bodyId()).textContent();
    emit newCommand(message.find(message.bodyId()).textContent());
}
