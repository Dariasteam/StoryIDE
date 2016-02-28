#ifndef RESALTADOR_H
#define RESALTADOR_H

#include <QSyntaxHighlighter>
#include <QTextDocument>
#include <QTextCharFormat>
#include <QRegExp>
#include <QStringList>
#include <QRegExp>

class Resaltador : public QSyntaxHighlighter
{
    Q_OBJECT
private:
    struct Regla{
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<Regla> highlightingRules;
    //Format
    QTextCharFormat formatoTitulo;
    QTextCharFormat formatoAutor;
    QTextCharFormat formatoOpcion;
    QTextCharFormat formatoSaltoIncondicional;
    QTextCharFormat formatoSaltoProbabilistico;
    QTextCharFormat formatoBloqueProbabilistico;
    QTextCharFormat formatoEtiqueta;

    //Regex
    QRegExp* etiqueta;
    QRegExp* saltoIncondicional;
    QRegExp* saltoProbabilistico;
    QRegExp* bloqueProbabilistico;
    QRegExp* autor;
    QRegExp* titulo;
    QRegExp* opcion;
    QRegExp* comentario;
    QPalette* paleta;
public:
    Resaltador(QTextDocument* parent = 0);
protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;
};

#endif // RESALTADOR_H