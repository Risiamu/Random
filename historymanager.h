#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H

#include <QObject>
#include <QStringList>

/**
 * @brief The HistoryManager class manages the history of generated strings
 * in the current session.
 */
class HistoryManager : public QObject {
    Q_OBJECT

public:
    explicit HistoryManager(QObject* parent = nullptr);
    
    /**
     * @brief addString Adds a string to the history
     * @param str The string to add
     */
    void addString(const QString& str);
    
    /**
     * @brief getHistory Gets the list of all strings in the history
     * @return The list of strings
     */
    QStringList getHistory() const;
    
    /**
     * @brief clearHistory Clears the history
     */
    void clearHistory();
    
    /**
     * @brief getHistorySize Gets the number of strings in the history
     * @return The number of strings
     */
    int getHistorySize() const;

signals:
    /**
     * @brief historyChanged Signal emitted when the history changes
     * @param history The updated history
     */
    void historyChanged(const QStringList& history);

private:
    QStringList m_history;
};

#endif // HISTORYMANAGER_H