#ifndef STRUCTUREINFO_H
#define STRUCTUREINFO_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>

namespace Ui {
class StructureInfo;
}

class StructureInfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit StructureInfo(QWidget *parent = 0);
    ~StructureInfo();
    void AddRoot(QString name, QString Description);
    void AddChild(QTreeWidgetItem *parent, QString name, QString Description);

private slots:
    void on_pushButton_clicked();

private:
    Ui::StructureInfo *ui;
};

#endif // STRUCTUREINFO_H
