#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <QObject>
#include <QtCore/QStringList>

class AbstractCommand : public QObject
{
    Q_OBJECT
public:
    explicit AbstractCommand(QObject *parent = 0);
    virtual QStringList supportedCommands() const = 0;

signals:
    void outputReady(const QString &output);

public slots:
    virtual void processCommand(const QStringList &commandLine) = 0;
};

#endif // ABSTRACTCOMMAND_H
