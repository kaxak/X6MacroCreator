/*
Copyright � ROCHE Emmanuel, 2012

git@kaxak.net

Ce logiciel est un programme informatique servant � cr�er et �diter des macros pour clavier.

Ce logiciel est r�gi par la licence CeCILL soumise au droit fran�ais et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffus�e par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilit� au code source et des droits de copie,
de modification et de redistribution accord�s par cette licence, il n'est
offert aux utilisateurs qu'une garantie limit�e.  Pour les m�mes raisons,
seule une responsabilit� restreinte p�se sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les conc�dants successifs.

A cet �gard  l'attention de l'utilisateur est attir�e sur les risques
associ�s au chargement,  � l'utilisation,  � la modification et/ou au
d�veloppement et � la reproduction du logiciel par l'utilisateur �tant
donn� sa sp�cificit� de logiciel libre, qui peut le rendre complexe �
manipuler et qui le r�serve donc � des d�veloppeurs et des professionnels
avertis poss�dant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invit�s � charger  et  tester  l'ad�quation  du
logiciel � leurs besoins dans des conditions permettant d'assurer la
s�curit� de leurs syst�mes et ou de leurs donn�es et, plus g�n�ralement,
� l'utiliser et l'exploiter dans les m�mes conditions de s�curit�.

Le fait que vous puissiez acc�der � cet en-t�te signifie que vous avez
pris connaissance de la licence CeCILL, et que vous en avez accept� les
termes.
---------------------------------------------------------------------------------------------
Copyright � ROCHE Emmanuel, 2012

git@kaxak.net

This software is a computer program whose purpose is to create and to edit keyboard macros.

This software is governed by the CeCILL license under French law and
abiding by the rules of distribution of free software.  You can  use,
modify and/ or redistribute the software under the terms of the CeCILL
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info".

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability.

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or
data to be ensured and,  more generally, to use and operate it in the
same conditions as regards security.

The fact that you are presently reading this means that you have had
knowledge of the CeCILL license and that you accept its terms.
*/


#ifndef KEYSTICKER_H
#define KEYSTICKER_H

#define STIKER_SIZE 64

#include <QtGui>
#include <QtCore>

#include "main.h"

class KeySticker : public QGraphicsWidget
{
    Q_OBJECT

public:
    //CONSTRUCTEUR
    KeySticker(QGraphicsItem *parent = 0);
    KeySticker(int id, QString text, int directIputID, int time, bool down, X::KeyType type,  QGraphicsItem *parent = 0);

    //METHODE
    int id();
    int keyDI();
    void setKeyDI(int);
    int keyTime();
    void setKeyTime(int);
    int selected();
    void setSelected(int);
    X::KeyType keyType();
    void setKeyType(X::KeyType);
    bool keyDown();
    void formatKeyText(QString text, X::KeyType type);


    //SURCHARGE
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget * = 0);
    void mousePressEvent (QGraphicsSceneMouseEvent *event);


signals:
    void clicked(int);

private slots:
    void updateKeyTime(int);



private:
    int m_id;
    int m_keyDI;
    QString m_keyText[2];
    int m_keyTime;
    int m_selected;//0 not selected, 1 main selected, 2 second selected
    X::KeyType m_keyType;
    bool m_keyDown;


};

#endif // KEYSTICKER_H
