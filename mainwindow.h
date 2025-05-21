#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QListWidget>
#include <QGroupBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QMessageBox>

#include "mainviewmodel.h"

/**
 * @brief The MainWindow class represents the main UI of the application
 */
class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    /**
     * @brief onGenerateClicked Slot called when the generate button is clicked
     */
    void onGenerateClicked();
    
    /**
     * @brief onCopyClicked Slot called when the copy button is clicked
     */
    void onCopyClicked();
    
    /**
     * @brief onClearHistoryClicked Slot called when the clear history button is clicked
     */
    void onClearHistoryClicked();
    
    /**
     * @brief onStringGenerated Slot called when a string is generated
     * @param str The generated string
     */
    void onStringGenerated(const QString& str);
    
    /**
     * @brief onStringCopied Slot called when a string is copied to clipboard
     * @param str The copied string
     */
    void onStringCopied(const QString& str);
    
    /**
     * @brief onHistoryChanged Slot called when the history changes
     * @param history The updated history
     */
    void onHistoryChanged(const QStringList& history);
    
    /**
     * @brief onConfigChanged Slot called when the configuration changes
     */
    void onConfigChanged();

private:
    MainViewModel* m_viewModel;
    
    // UI elements
    QWidget* m_centralWidget;
    QVBoxLayout* m_mainLayout;
    
    // Generated string display
    QLineEdit* m_generatedStringEdit;
    QPushButton* m_generateButton;
    QPushButton* m_copyButton;
    
    // Configuration
    QGroupBox* m_configGroupBox;
    QGridLayout* m_configLayout;
    QCheckBox* m_uppercaseCheckBox;
    QCheckBox* m_lowercaseCheckBox;
    QCheckBox* m_numbersCheckBox;
    QCheckBox* m_dashCheckBox;
    QLineEdit* m_customCharsetEdit;
    QLabel* m_lengthLabel;
    QSpinBox* m_lengthSpinBox;
    
    // History
    QGroupBox* m_historyGroupBox;
    QVBoxLayout* m_historyLayout;
    QListWidget* m_historyListWidget;
    QPushButton* m_clearHistoryButton;
    
    /**
     * @brief setupUi Sets up the UI elements
     */
    void setupUi();
    
    /**
     * @brief connectSignalsAndSlots Connects signals and slots
     */
    void connectSignalsAndSlots();
    
    /**
     * @brief updateConfigFromUi Updates the configuration from UI elements
     */
    void updateConfigFromUi();
};

#endif // MAINWINDOW_H