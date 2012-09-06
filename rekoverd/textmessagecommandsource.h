#ifndef TEXTMESSAGECOMMANDSOURCE_H
#define TEXTMESSAGECOMMANDSOURCE_H

#include "abstractcommandsource.h"

#include <QtMessaging/QMessageManager>

QTM_USE_NAMESPACE

class TextMessageCommandSource : public AbstractCommandSource
{
    Q_OBJECT
public:
    explicit TextMessageCommandSource(QObject *parent = 0);
    
signals:
    
private slots:
    void sendResponseImpl(const QString &response);

private slots:
    void processNewMessage(QMessageId id,QMessageManager::NotificationFilterIdSet set);

private:
    QMessageManager m_messageManager;
};

#endif // TEXTMESSAGECOMMANDSOURCE_H
