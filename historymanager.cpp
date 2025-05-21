#include "historymanager.h"

HistoryManager::HistoryManager(QObject* parent)
    : QObject(parent) {
}

void HistoryManager::addString(const QString& str) {
    // Don't add empty strings
    if (str.isEmpty()) {
        return;
    }
    
    // Add the string to the history
    m_history.prepend(str); // Add to the beginning so newest is first
    
    // Emit the signal that the history has changed
    emit historyChanged(m_history);
}

QStringList HistoryManager::getHistory() const {
    return m_history;
}

void HistoryManager::clearHistory() {
    m_history.clear();
    emit historyChanged(m_history);
}

int HistoryManager::getHistorySize() const {
    return m_history.size();
}