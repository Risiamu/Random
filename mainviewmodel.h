#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include <QObject>
#include <QClipboard>
#include <QApplication>
#include <QStringList>

#include "stringgenerator.h"
#include "historymanager.h"
#include "configmanager.h"

/**
 * @brief The MainViewModel class connects the Model and View components
 * following the MVVM design pattern.
 */
class MainViewModel : public QObject {
    Q_OBJECT

public:
    explicit MainViewModel(QObject* parent = nullptr);
    ~MainViewModel();

    /**
     * @brief generateString Generates a random string based on current configuration
     * @return The generated string
     */
    QString generateString();
    
    /**
     * @brief copyToClipboard Copies the given string to clipboard
     * @param str The string to copy
     */
    void copyToClipboard(const QString& str);
    
    /**
     * @brief getHistory Gets the list of generated strings
     * @return The list of generated strings
     */
    QStringList getHistory() const;
    
    /**
     * @brief clearHistory Clears the history of generated strings
     */
    void clearHistory();
    
    /**
     * @brief getConfigManager Gets the configuration manager
     * @return The configuration manager
     */
    ConfigManager* getConfigManager() const;
    
    /**
     * @brief getHistoryManager Gets the history manager
     * @return The history manager
     */
    HistoryManager* getHistoryManager() const;

signals:
    /**
     * @brief stringGenerated Signal emitted when a string is generated
     * @param str The generated string
     */
    void stringGenerated(const QString& str);
    
    /**
     * @brief stringCopied Signal emitted when a string is copied to clipboard
     * @param str The copied string
     */
    void stringCopied(const QString& str);

private:
    StringGenerator* m_stringGenerator;
    HistoryManager* m_historyManager;
    ConfigManager* m_configManager;
    
    /**
     * @brief updateStringGenerator Updates the string generator with current configuration
     */
    void updateStringGenerator();
};

#endif // MAINVIEWMODEL_H