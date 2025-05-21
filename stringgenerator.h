#ifndef STRINGGENERATOR_H
#define STRINGGENERATOR_H

#include <QString>
#include <QSet>
#include <random>

/**
 * @brief The StringGenerator class handles the generation of random strings
 * based on configurable character sets.
 */
class StringGenerator {
public:
    StringGenerator();
    
    /**
     * @brief generateRandomString Generates a random string based on the current configuration
     * @param length The length of the string to generate
     * @return The generated random string
     */
    QString generateRandomString(int length = 10);
    
    /**
     * @brief setUseUppercase Sets whether to include uppercase letters in the character set
     * @param use True to include uppercase letters, false otherwise
     */
    void setUseUppercase(bool use);
    
    /**
     * @brief setUseLowercase Sets whether to include lowercase letters in the character set
     * @param use True to include lowercase letters, false otherwise
     */
    void setUseLowercase(bool use);
    
    /**
     * @brief setUseNumbers Sets whether to include numbers in the character set
     * @param use True to include numbers, false otherwise
     */
    void setUseNumbers(bool use);
    
    /**
     * @brief setUseDash Sets whether to include dash (-) in the character set
     * @param use True to include dash, false otherwise
     */
    void setUseDash(bool use);
    
    /**
     * @brief setCustomCharset Sets a custom character set to use
     * @param charset The custom character set
     */
    void setCustomCharset(const QString& charset);
    
    /**
     * @brief getCurrentCharset Gets the current character set being used
     * @return The current character set
     */
    QString getCurrentCharset() const;

private:
    bool m_useUppercase;
    bool m_useLowercase;
    bool m_useNumbers;
    bool m_useDash;
    QString m_customCharset;
    
    std::random_device m_rd;
    std::mt19937 m_generator;
    
    /**
     * @brief buildCharset Builds the character set based on current configuration
     * @return The built character set
     */
    QString buildCharset() const;
};

#endif // STRINGGENERATOR_H