#ifndef CHECKFILES_H
#define CHECKFILES_H
#include <QMainWindow>


class CheckFiles :public QMainWindow
{
    Q_OBJECT
public:
     explicit CheckFiles(QWidget *parent = nullptr);

public:
    //CheckFiles();
    void init();
    void initDB();
    void initMkDir();
    void initKontrahent();
    void initZapisMiasta();
    void initZapisModel();
    void initZapisNrSeryjny();
    void initZapisProducenta();
    void initZapisWojewodztwa();
    void initZapisKraj();
    void initCheckFlagsInMiasto();
    void initCheckFlagsInWojewodztwa();
    void initCheckFlagsInKrajKontrahentShow();
    void initCheckFlagsInMiastoKontrahentShow();
    void initCheckFlagsInWojewodztwoKontrahentShow();
    void initCheckFlagsInKraj();
    void initCheckFlagsProducent();
    void initCheckFlagsInProducentUrzadzenia();
    void initCheckFlagsInModelUrzadzenia();
    int checkFlagsMiasto(int checkFlagsVarriable);
    int checkFlagsWojewodztwa(int checkFlagsVarriableWojewodztwo);
    int checkFlagsKraj(int checkFlagsVarriableKraj); //int checkFlagsVarriableKraj
    int checkFlagsProducent(int checkFlagsVarriableProducent);

    int checkFlagsModel(int checkFlagsVarriableModel);
    void initUrzadzenie();





};

#endif // CHECKFILES_H
