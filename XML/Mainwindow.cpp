#include "Mainwindow.h"
#include "ui_Mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //C:\Users\Nicole\Dropbox\QT Shit\QT Experimental Programs\XML
    //create the model - Be careful here it does matter between \ and what you should use /
    filename = "C:/Users/Nicole/Documents/QT Experimental Programs/XML/MyXML.xml";
    model = new QStandardItemModel(0,1,this);
    readFile();
    ui->treeView->setModel(model);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFile()
{
    QStandardItem *root = new QStandardItem("Books");
    model->appendRow(root);
    QDomDocument document;

    //load the xml file
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        document.setContent(&file);
        file.close();
    }

    //get the xml root
    QDomElement xmlRoot = document.firstChildElement();

    //read the books
    QDomNodeList books = xmlRoot.elementsByTagName("Book");

    for(int i =0; i < books.count(); i++)
    {
        QDomElement book = books.at(i).toElement();
        QStandardItem *booksItem = new QStandardItem(book.attribute("Name"));

        //read the chapters of the books
        QDomNodeList chapters = xmlRoot.elementsByTagName("Chapter");
        for(int j =0; j < chapters.count(); j++)
        {
            QDomElement chapter = chapters.at(j).toElement();
            QStandardItem *chapterItem = new QStandardItem(chapter.attribute("Name"));

            booksItem->appendRow(chapterItem);
        }

        root->appendRow(booksItem);

    }

}

void MainWindow::writeFile()
{
    //write the xml file
    QDomDocument document;

    //Make a root node
    QDomElement xmlroot = document.createElement("Books");
    document.appendChild(xmlroot);

    QStandardItem *root = model->item(0,0);
    for(int i = 0; i < root->rowCount(); i++)
    {
        QStandardItem *book = root->child(i,0);

        QDomElement xmlbook = document.createElement("Book");
        xmlbook.setAttribute("Name",book->text());
        xmlbook.setAttribute("ID", i);
        xmlroot.appendChild(xmlbook);

        for(int h = 0; h < book->rowCount(); h++)
        {
            QStandardItem *chapter = book->child(h,0);
            QDomElement xmlchapter = document.createElement("Chapter");
            xmlchapter.setAttribute("Name",chapter->text());
            xmlchapter.setAttribute("ID", h);
            xmlbook.appendChild(xmlchapter);
        }
    }

    //save to disk
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Failed to write file";
    }

    QTextStream stream(&file);
    stream << document.toString();
    file.close();

     qDebug() << "Finished";
}

void MainWindow::on_pushButton_clicked()
{
    //save the document
    writeFile();
}
