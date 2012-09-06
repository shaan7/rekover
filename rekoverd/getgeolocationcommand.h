#ifndef GETGEOLOCATIONCOMMAND_H
#define GETGEOLOCATIONCOMMAND_H

#include "abstractcommand.h"

class GetGeolocationCommand : public AbstractCommand
{
    Q_OBJECT
public:
    explicit GetGeolocationCommand(QObject *parent = 0);
    QStringList supportedCommands() const;

signals:
    
public slots:
    void processCommand(const QStringList &commandLine);
};

#endif // GETGEOLOCATIONCOMMAND_H
