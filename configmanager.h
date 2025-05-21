#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QObject>
#include <QString>

/**
 * @brief The ConfigManager class manages the configuration for string generation
 */
class ConfigManager : public QObject {
    Q_OBJECT

public:
    explicit ConfigManager(QObject* parent = nullptr);
    
    /**
     * @brief setUseUppercase Sets whether to include uppercase letters
     * @param use True to include uppercase letters, false otherwise
     */
    void setUseUppercase(bool use);
    
    /**
     * @brief useUppercase Gets whether uppercase letters are included
     * @return True if uppercase letters are included, false otherwise
     */
    bool useUppercase() const;
    
    /**
     * @brief setUseLowercase Sets whether to include lowercase letters
     * @param use True to include lowercase letters, false otherwise
     */
    void setUseLowercase(bool use);
    
    /**
     * @brief useLowercase Gets whether lowercase letters are included
     * @return True if lowercase letters are included, false otherwise
     */
    bool useLowercase() const;
    
    /**
     * @brief setUseNumbers Sets whether to include numbers
     * @param use True to include numbers, false otherwise
     */
    void setUseNumbers(bool use);
    
    /**
     * @brief useNumbers Gets whether numbers are included
     * @return True if numbers are included, false otherwise
     */
    bool useNumbers() const;
    
    /**
     * @brief setUseDash Sets whether to include dash (-)
     * @param use True to include dash, false otherwise
     */
    void setUseDash(bool use);
    
    /**
     * @brief useDash Gets whether dash is included
     * @return True if dash is included, false otherwise
     */
    bool useDash() const;
    
    /**
     * @brief setCustomCharset Sets a custom character set
     * @param charset The custom character set
     */
    void setCustomCharset(const QString& charset);
    
    /**
     * @brief customCharset Gets the custom character set
     * @return The custom character set
     */
    QString customCharset() const;
    
    /**
     * @brief setStringLength Sets the length of generated strings
     * @param length The length to set
     */
    void setStringLength(int length);
    
    /**
     * @brief stringLength Gets the length of generated strings
     * @return The length of generated strings
     */
    int stringLength() const;

signals:
    /**
     * @brief configChanged Signal emitted when the configuration changes
     */
    void configChanged();

private:
    bool m_useUppercase;
    bool m_useLowercase;
    bool m_useNumbers;
    bool m_useDash;
    QString m_customCharset;
    int m_stringLength;
};

#endif // CONFIGMANAGER_H