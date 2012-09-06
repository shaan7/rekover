#ifndef COMMANDPROCESSOR_H
#define COMMANDPROCESSOR_H

#include <QObject>
#include <QtCore/QHash>
#include <QtCore/QStringList>
#include <QtCore/QList>

#include "abstractcommand.h"
#include "abstractcommandsource.h"

class CommandProcessor : public QObject
{
    Q_OBJECT
public:
    explicit CommandProcessor(QObject *parent = 0);
    void connectToCommandSource(AbstractCommandSource *commandSource);
    void addCommand(AbstractCommand *command);
    
signals:
    
public slots:
    void processCommand(const QString commandLine);

private:
    QHash<QString, AbstractCommand*> m_commands;
    QList<AbstractCommandSource*> m_sources;
};

#endif // COMMANDPROCESSOR_H
