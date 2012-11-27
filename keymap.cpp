/*
Copyright © ROCHE Emmanuel, 2012

git@kaxak.net

Ce logiciel est un programme informatique servant à créer et éditer des macros pour clavier.

Ce logiciel est régi par la licence CeCILL soumise au droit français et
respectant les principes de diffusion des logiciels libres. Vous pouvez
utiliser, modifier et/ou redistribuer ce programme sous les conditions
de la licence CeCILL telle que diffusée par le CEA, le CNRS et l'INRIA
sur le site "http://www.cecill.info".

En contrepartie de l'accessibilité au code source et des droits de copie,
de modification et de redistribution accordés par cette licence, il n'est
offert aux utilisateurs qu'une garantie limitée.  Pour les mêmes raisons,
seule une responsabilité restreinte pèse sur l'auteur du programme,  le
titulaire des droits patrimoniaux et les concédants successifs.

A cet égard  l'attention de l'utilisateur est attirée sur les risques
associés au chargement,  à l'utilisation,  à la modification et/ou au
développement et à la reproduction du logiciel par l'utilisateur étant
donné sa spécificité de logiciel libre, qui peut le rendre complexe à
manipuler et qui le réserve donc à des développeurs et des professionnels
avertis possédant  des  connaissances  informatiques approfondies.  Les
utilisateurs sont donc invités à charger  et  tester  l'adéquation  du
logiciel à leurs besoins dans des conditions permettant d'assurer la
sécurité de leurs systèmes et ou de leurs données et, plus généralement,
à l'utiliser et l'exploiter dans les mêmes conditions de sécurité.

Le fait que vous puissiez accéder à cet en-tête signifie que vous avez
pris connaissance de la licence CeCILL, et que vous en avez accepté les
termes.
---------------------------------------------------------------------------------------------
Copyright © ROCHE Emmanuel, 2012

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


#define KMAP(d,x,s,t) m_keyMap.push_back(new KeyCode(d, x, s, t))


#include "keymap.h"

KeyMap::KeyMap(){
    KMAP(1,1,"Echap",X::keyText);
    KMAP(2,2,"1 &",X::keyDefault);
    KMAP(3,3,"2 é~",X::keyDefault);
    KMAP(4,4,"3 \"#",X::keyDefault);
    KMAP(5,5,"4 '{",X::keyDefault);
    KMAP(6,6,"5 ([",X::keyDefault);
    KMAP(7,7,"6 -|",X::keyDefault);
    KMAP(8,8,"7 è`",X::keyDefault);
    KMAP(9,9,"8 _\\",X::keyDefault);
    KMAP(10,10,"9 ç^",X::keyDefault);
    KMAP(11,11,"0 à@",X::keyDefault);
    KMAP(12,12,"° )]",X::keyDefault);
    KMAP(13,13,"+ =}",X::keyDefault);
    KMAP(14,14,"backspace.png",X::keyImg);
    KMAP(15,15,"tabule.png",X::keyImg);
    KMAP(16,16,"A",X::keyDefault);
    KMAP(17,17,"Z",X::keyDefault);
    KMAP(18,18,"E",X::keyDefault);
    KMAP(19,19,"R",X::keyDefault);
    KMAP(20,20,"T",X::keyDefault);
    KMAP(21,21,"Y",X::keyDefault);
    KMAP(22,22,"U",X::keyDefault);
    KMAP(23,23,"I",X::keyDefault);
    KMAP(24,24,"O",X::keyDefault);
    KMAP(25,25,"P",X::keyDefault);
    KMAP(26,26,"¨ ^",X::keyDefault);
    KMAP(27,27,"£ $¤",X::keyDefault);
    KMAP(28,28,"enter.png",X::keyImg);
    KMAP(29,29,"ctrl_left.png",X::keyImg);
    KMAP(30,30,"Q",X::keyDefault);
    KMAP(31,31,"S",X::keyDefault);
    KMAP(32,32,"D",X::keyDefault);
    KMAP(33,33,"F",X::keyDefault);
    KMAP(34,34,"G",X::keyDefault);
    KMAP(35,35,"H",X::keyDefault);
    KMAP(36,36,"J",X::keyDefault);
    KMAP(37,37,"K",X::keyDefault);
    KMAP(38,38,"L",X::keyDefault);
    KMAP(39,39,"M",X::keyDefault);
    KMAP(40,40,"% ù",X::keyDefault);
    KMAP(41,41,"²",X::keyDefault);
    KMAP(42,42,"shift_left.png",X::keyImg);
    KMAP(43,43,"µ *",X::keyDefault);
    KMAP(44,44,"W",X::keyDefault);
    KMAP(45,45,"X",X::keyDefault);
    KMAP(46,46,"C",X::keyDefault);
    KMAP(47,47,"V",X::keyDefault);
    KMAP(48,48,"B",X::keyDefault);
    KMAP(49,49,"N",X::keyDefault);
    KMAP(50,50,"? ,",X::keyDefault);
    KMAP(51,51,". ;",X::keyDefault);
    KMAP(52,52,"/ :",X::keyDefault);
    KMAP(53,53,"§ !",X::keyDefault);
    KMAP(54,54,"shift_right.png",X::keyImg);
    KMAP(55,55,"KP_*",X::keyText);
    KMAP(56,56,"Alt",X::keyText);
    KMAP(57,57,"Espace",X::keyText);
    KMAP(58,58,"Ver. Maj.",X::keyText);
    KMAP(59,59,"F1",X::keyDefault);
    KMAP(60,60,"F2",X::keyDefault);
    KMAP(61,61,"F3",X::keyDefault);
    KMAP(62,62,"F4",X::keyDefault);
    KMAP(63,63,"F5",X::keyDefault);
    KMAP(64,64,"F6",X::keyDefault);
    KMAP(65,65,"F7",X::keyDefault);
    KMAP(66,66,"F8",X::keyDefault);
    KMAP(67,67,"F9",X::keyDefault);
    KMAP(68,68,"F10",X::keyDefault);
    KMAP(69,69,"Verr. Num.",X::keyText);
    KMAP(70,70,"Arrêt défil.",X::keyText);
    KMAP(71,71,"KP_7",X::keyText);
    KMAP(72,72,"KP_8",X::keyText);
    KMAP(73,73,"KP_9",X::keyText);
    KMAP(74,74,"KP_-",X::keyText);
    KMAP(75,75,"KP_4",X::keyText);
    KMAP(76,76,"KP_5",X::keyText);
    KMAP(77,77,"KP_6",X::keyText);
    KMAP(78,78,"KP_+",X::keyText);
    KMAP(79,79,"KP_1",X::keyText);
    KMAP(80,80,"KP_2",X::keyText);
    KMAP(81,81,"KP_3",X::keyText);
    KMAP(82,82,"KP_0",X::keyText);
    KMAP(83,83,"KP_.",X::keyText);
    KMAP(84,84,"KP_2",X::keyText);

    KMAP(86,86,"> <",X::keyDefault);
    KMAP(87,87,"F11",X::keyDefault);
    KMAP(88,88,"F12",X::keyDefault);

    KMAP(156,156,"Entrée",X::keyText);
    KMAP(157,157,"ctrl_right.png",X::keyImg);

    KMAP(181,181,"KP_/",X::keyText);

    KMAP(183,183,"Impr. écran",X::keyText);
    KMAP(184,57400,"Alt Gr",X::keyText);

    KMAP(197,197,"Pause",X::keyText);

    KMAP(199,199,"home.png",X::keyImg);
    KMAP(200,57416,"up.png",X::keyImg);
    KMAP(201,201,"page_up.png",X::keyImg);

    KMAP(203,57419,"left.png",X::keyImg);

    KMAP(205,57421,"right.png",X::keyImg);

    KMAP(207,207,"Fin",X::keyText);
    KMAP(208,57424,"down.png",X::keyImg);
    KMAP(209,209,"page_down.png",X::keyImg);
    KMAP(210,210,"insér.",X::keyText);
    KMAP(211,211,"Suppr.",X::keyText);

    KMAP(219,57435,"win.png",X::keyImg);

    KMAP(221,221,"context.png",X::keyImg);

    //souris
    KMAP(301,1,"mouse1.png",X::keyMouse);
    KMAP(302,2,"mouse2.png",X::keyMouse);
    KMAP(303,3,"mouse3.png",X::keyMouse);
    KMAP(304,4,"mouse4.png",X::keyMouse);
    KMAP(305,5,"mouse5.png",X::keyMouse);

}

KeyMap::KeyCode::KeyCode(int keyDI, int keyX6, QString keySticker, X::KeyType keyType){
    m_keyDI=keyDI;
    m_keyX6=keyX6;
    m_keySticker=keySticker;
    m_keyType=keyType;
}

//METHODE//METHODE//METHODE//METHODE//METHODE//METHODE//METHODE//METHODE
int KeyMap::toDI(int keyX6){
    for(int i=0;i<m_keyMap.size();i++){
        if(m_keyMap[i]->m_keyX6 == keyX6) return m_keyMap[i]->m_keyDI;
    }
    return 0;
}

int KeyMap::toX6(int keyDI){
    for(int i=0;i<m_keyMap.size();i++){
        if(m_keyMap[i]->m_keyDI == keyDI) return m_keyMap[i]->m_keyX6;
    }
    return 0;
}

QString KeyMap::toSticker(int keyDI){
    for(int i=0;i<m_keyMap.size();i++){
        if(m_keyMap[i]->m_keyDI == keyDI) return m_keyMap[i]->m_keySticker;
    }
    return QString("unknown");
}

X::KeyType KeyMap::type(int keyDI){
    for(int i=0;i<m_keyMap.size();i++){
        if(m_keyMap[i]->m_keyDI == keyDI) return m_keyMap[i]->m_keyType;
    }
    return X::keyText;
}
