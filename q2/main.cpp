#include "LinkedList.h"
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	string input[] = {"Eagle", "Alpha", "Golf", "Delta", "Charlie", "Fox",  "Hotel", "Bravo"};
    
    LinkedList list;

    for(auto s : input)
        list.insertEnd(s);

    auto status = list.checkConsistency();

    if(status != OK)
    {
        cout << "ERRO: Há uma inconsistência na lista após a inserção. Código de erro: " << status << ".\nVer enum ListStatus no arquivo LinkedList.h para entender qual problema foi identificado.\n";
        return -1;
    }


    cout << "Lista antes de ordenar:\n";
    list.print();

    list.sort();

    cout << "Lista depois de ordenar:\n";
    list.print();

    status = list.checkConsistency();

    if(status != OK)
    {
        cout << "ERRO: Há uma inconsistência na lista após a ordenação. Código de erro: " << status << ".\nVer enum ListStatus no arquivo LinkedList.h para entender qual problema foi identificado.\n";
        return -1;
    }

    bool isOrdered = list.isOrdered();


    if(isOrdered)
    {
        cout << "\n\nQ3 - Testes OK.\n";
    } 
    else
    {
        cout << "\n\n!!!! ERRO - Não ordenou a lista corretamente.\n";
    }
	
	return 0;
}
