#ifndef ACERCADE_H
#define ACERCADE_H

#include <QMainWindow>

namespace Ui {
class Acercade;
}

class Acercade : public QMainWindow
{
    Q_OBJECT

public:
    explicit Acercade(QWidget *parent = nullptr);
    ~Acercade();

private:
    Ui::Acercade *ui;
};

#endif // ACERCADE_H
