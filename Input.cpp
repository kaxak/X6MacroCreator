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


#include "Input.h"

Input::Input(){
    m_directInput=0;
    m_keyboard=0;
    for(int i = 0;i< 256;i++){
        m_keyboardState[i]=0;
    }
}
Input::~Input(){
    release();
}

bool Input::init(HINSTANCE hinstance, HWND hwnd){
    HRESULT result;

    // Initialize the main direct input interface.
    result = DirectInput8Create(hinstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_directInput, NULL);
    if(FAILED(result)){
        // Erreurs possibles : DIERR_DEVICENOTREG, DIERR_INVALIDPARAM, DIERR_NOINTERFACE, DIERR_NOTINITIALIZED, DIERR_OUTOFMEMORY
        QMessageBox::information(0,"Erreur : Direct Input","DirectInput8Create");
        return false;
    }

    // Initialize the direct input interface for the keyboard.
    result = m_directInput->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);
    if(FAILED(result)) {
        QMessageBox::information(0,"Erreur : Direct Input","CreateDevice");
        return false;
    }

    // Set the data format.  In this case since it is a keyboard we can use the predefined data format.
    result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
    if(FAILED(result)){
        QMessageBox::information(0,"Erreur : Direct Input","SetDataFormat");
        return false;
    }
        // Set the cooperative level of the keyboard to not share with other programs.
    result = m_keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
    if(FAILED(result)) {
        QMessageBox::information(0,"Erreur : Direct Input","SetCooperativeLevel");
        return false;
    }
    return true;
}

void Input::release(){
    if(m_keyboard){
        m_keyboard->Unacquire();
        m_keyboard->Release();
        m_keyboard = 0;
    }
    if(m_directInput){
        m_directInput->Release();
        m_directInput = 0;
    }
}

bool Input::acquire(){
    HRESULT result;
    result = m_keyboard->GetDeviceState(sizeof(m_keyboardState), (LPVOID)&m_keyboardState);
    if(FAILED(result)){
        if((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED)){
            m_keyboard->Acquire();
        }
        else{
            QMessageBox::information(0,"Erreur : Direct Input","Acquire");
            return false;
        }
    }
    return true;
}

bool Input::key(char k){
    if(m_keyboardState[k] & 0x80) {
        return true;
    }
    return false;
}

int Input::keyWhat(){
    for(int i = 0;i< 256;i++){
        if(m_keyboardState[i]){

        }
    }
    return 0;
}
unsigned char* Input::keyboardStat(){
    return m_keyboardState;
}
