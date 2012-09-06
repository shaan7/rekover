#include "abstractcommandsource.h"

AbstractCommandSource::AbstractCommandSource(QObject *parent) :
    QObject(parent)
{
}

void AbstractCommandSource::sendResponse(const QString &response)
{
    disconnect(sender());
    sendResponseImpl(response);
}
