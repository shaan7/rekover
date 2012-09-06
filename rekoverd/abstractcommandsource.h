#ifndef ABSTRACTCOMMANDSOURCE_H
#define ABSTRACTCOMMANDSOURCE_H

#include <QObject>

class AbstractCommandSource : public QObject
{
    Q_OBJECT
public:
    explicit AbstractCommandSource(QObject *parent = 0);
    
signals:
    void newCommand(const QString &commandLine);

public slots:
    void sendResponse(const QString &response);

private slots:
    virtual void sendResponseImpl(const QString &response) = 0;
};

#endif // ABSTRACTCOMMANDSOURCE_H
