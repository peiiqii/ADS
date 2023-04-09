#include "List.h"
#include <iostream>
List::List()
{
    /*
        Konstruktor f�r eine leere Liste
    */
    m_head_tail = new Node;
    m_list_size = 0;
    m_temp = false;
    m_head_tail->next = m_head_tail;
    m_head_tail->prev = m_head_tail;
}

List::List(const List& _List)
{
    /*
        Konstruktor mit �bergabe einer Liste, die dann kopiert wird.
        in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
        sollen.
    */
    list_form = _List.list_form;
    m_head_tail = new Node;
    m_list_size = 0;
    m_temp = _List.m_temp;
    m_head_tail->next = m_head_tail;
    m_head_tail->prev = m_head_tail;
    Node* tmp_node;
    tmp_node = _List.m_head_tail->next;
    while (tmp_node != _List.m_head_tail)
    {
        m_head_tail->prev =
            new Node(tmp_node->value, m_head_tail->prev->next, m_head_tail->prev);
        m_head_tail->prev->prev->next = m_head_tail->prev;
        m_list_size++;
        tmp_node = tmp_node->next;
    }
    /*
        Ist die �bergebene Liste eine m_tempor�re Liste? -> aus Operator +
    */
    if (_List.m_temp)
        delete& _List;
}

List::~List()
{
    //ToDo
/*
    Dekonstruktor
    Alle Knoten der Liste m�ssen gel�scht werden, wenn die Liste gel�scht wird.
*/

}

void List::insertFront(int value)
{
    //ToDo
/*
    Einfuegen eines neuen Knotens am Anfang der Liste
    Einen neuen Knoten mit dem Wert value wird am Anfang der Liste einf�gen
*/

}

void List::insertFront(List& _List)
{
    //ToDo
/*
    Einfuegen der Liste _List am Anfang an einer vorhandenen Liste
    Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
    Die einzufuegende Liste _List ist anschlie�end leer.
    Es darf keine Schleife und kein new benutzt werden.
*/
/*
    gleiches Objekt -> keine Aktion
*/
    if (m_head_tail == _List.m_head_tail) return;

    /*
        Es wird ein Objekt �bergeben in dem Knoten vorhanden sein k�nnen.
        Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) �bertragen ohne sie zu kopieren!
        Die Liste _List ist danach leer, aber vorhanden.
    */

}

void List::insertBack(int value)
{
    //ToDo
/*
    Einfuegen eines neuen Knotens am Ende der Liste
    Einen neuen Knoten mit dem Wert value wird am Ende der Liste einf�gen
*/

}

void List::insertBack(List& _List)
{
    //ToDo
/*
    Einfuegen der Liste _List am Ende einer vorhandenen Liste
    Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
    Die einzufuegende Liste _List ist anschlie�end leer.
    Es darf keine Schleife und kein new benutzt werden.
*/
/*
    gleiches Objekt -> keine Aktion
*/
    if (m_head_tail == _List.m_head_tail) return;

    /*
        Es wird ein Objekt �bergeben in dem Knoten vorhanden sein k�nnen.
        Diese Knoten (koplette Kette) werden an den Ende der Liste (this) �bertragen ohne sie zu kopieren!
        Die Liste _List ist danach leer, aber vorhanden.
    */

}

bool List::getFront(int& value)
{
    //ToDo
/*
    entnehmen des Knotens am Anfang der Liste
    der Wert wird als Parameter zurueckgegeben
    der Knoten wird entnommen
    im Fehlerfall wird false zur�ckgegeben
*/
/*
    gleiches Objekt -> keine Aktion
*/
    if (!m_list_size) return false;

    /*
        Der Wert des vorderen Knotens wird r�ckgegeben und der Knoten gel�scht.
        Die Methode del(value) darf nicht zum l�schen benutzt werden.
    */

}

bool List::getBack(int& value)
{
    //ToDo
/*
    entnehmen des Knotens am Ende der Liste
    der Wert wird als Parameter zurueckgegeben
    der Knoten wird entnommen
    im Fehlerfall wird false zur�ckgegeben
*/
/*
    gleiches Objekt -> keine Aktion
*/
    if (!m_list_size) return false;

    /*
        Der Wert des letzten Knotens wird r�ckgegeben und der Knoten gel�scht.
        Die Methode del(value) darf nicht zum l�schen benutzt werden.
    */

}

bool List::del(int value)
{
    //ToDo
/*
    Loeschen eines gegebenen Knotens
    im Fehlerfall wird false zur�ckgegeben
*/
/*
    gleiches Objekt -> keine Aktion
*/
    if (!m_list_size) return false;

    /*
        L�schen des Knotens mit dem Wert value
    */

}

bool List::search(int value)
{
    //ToDo
/*
    suchen eines Knotens
    nicht gefunden -> Rueckgabe: false
*/
/*
    leere Liste -> keine Aktion
*/
    if (!m_list_size) return false;

    /*
        suchen ob ein Knoten mit dem Wert value existiert.
    */

}

bool List::swap(int value1, int value2)
{
    //ToDo
/*
    Vertauschen von zwei Knoten
    Dabei werden die Zeiger der Knoten und deren Nachbarn veraendert.
    im Fehlerfall wird false zurueckgegeben
*/
/*
    Wenn Liste Leer oder weniger als 2 Knoten besitzt -> Keine Aktion
*/
    if (m_list_size < 2) return false;
    /*
        Vertauschen von zwei Knoten mit dem Wert value1 und dem Wert value2.
        Es duerfen nicht nur einfach die Werte in den Knoten getauscht werden!
        Die Knoten sind in der Kette umzuhaengen.
    */
    return true;
}

int List::size(void)
{
    //ToDo
/*
    Rueckgabe der Anzahl der Knoten in der Liste mit O(1)
    d.h. die Liste darf NICHT traversiert werden um die Gr��e zu bestimmen.

    Anzahl der Knoten in der Liste zur�ckgeben.
    Hier richtiges Ergebnis zur�ckgeben
*/
    return 0;
}

bool List::test(void)
{
    // Testmethode: die Methode durchl�uft die Liste vom Anfang bis zum Ende und
    // zur�ck Es werden dabei die Anzahl der Knoten gezahlt. Stimmt die Anzahl
    // der Knoten �berein liefert die Methode true
    Node* tmp = m_head_tail->next;
    int   i_next = 0, i_prev = 0;
    while (tmp != m_head_tail)
    {
        tmp = tmp->next;
        if (i_next > m_list_size)
            return false;
        i_next++;
    }
    if (i_next != m_list_size)
        return false;
    tmp = m_head_tail->prev;
    while (tmp != m_head_tail)
    {
        tmp = tmp->prev;
        if (i_prev > m_list_size)
            return false;
        i_prev++;
    }
    return i_prev == i_next;
}

List& List::operator=(const List& _List)
{
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
    // sollen. Kopiert wird in das Objekt "this"
    if (this == &_List)
        return *this; //  !! keine Aktion notwendig
    list_form = _List.list_form;
    Node* tmp_node;
    if (m_list_size)
    {
        Node* tmp_del;
        tmp_node = m_head_tail->next;
        while (tmp_node !=
            m_head_tail) // Alle eventuell vorhandenen Knoten in this l�schen
        {
            tmp_del = tmp_node;
            tmp_node = tmp_node->next;
            delete tmp_del;
        }
        m_list_size = 0;
        m_head_tail->next = m_head_tail;
        m_head_tail->prev = m_head_tail;
    }
    tmp_node = _List.m_head_tail->next; // Die Listen-Knotenwerte werden kopiert
    while (tmp_node != _List.m_head_tail)
    {
        insertBack(tmp_node->value);
        tmp_node = tmp_node->next;
    }
    if (_List.m_temp)
        delete& _List; // ist die �bergebene Liste eine m_tempor�re Liste? -> aus
                       // Operator +
    return *this;
}

List& List::operator+(const List& List_Append)
{
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht ver�ndert. Es entsteht eine neue
    // Ergebnisliste.
    Node* tmp_node;
    List* tmp;
    if (m_temp)
    { // this ist eine m_tempor�re Liste und kann ver�ndert werden
        tmp = this;
    }
    else
    {
        tmp =
            new List(*this); // this ist keine m_tempor�re Liste -> Kopie erzeugen
        tmp->m_temp = true;    // Merker setzten, dass es sich um eine m_tempor�re
                             // Liste handelt
    }
    if (List_Append.m_list_size)
    { // anh�ngen der �bergebenen Liste an tmp
        tmp_node = List_Append.m_head_tail->next;
        while (tmp_node != List_Append.m_head_tail)
        {
            tmp->insertBack(tmp_node->value);
            tmp_node = tmp_node->next;
        }
    }
    if (List_Append.m_temp)
        delete& List_Append; // wurde eine m_tempor�re Liste �bergeben, dann wird
                             // diese gel�scht
    return *tmp;
}

void List::format(const std::string& start,
    const std::string& zwischen,
    const std::string& ende)
{
    // Setzen des Formates f�r die Ausgabesteuerung der Liste bei cout
    // das Format wird f�r den �berladenen Operator << verwendet
    list_form.start = start;
    list_form.zwischen = zwischen;
    list_form.ende = ende;
}

std::ostream& operator<<(std::ostream& stream, List const& Liste)
{
    // Ausgabe der Liste mit cout
    stream << Liste.list_form.start;
    for (Node* tmp = Liste.m_head_tail->next; tmp != Liste.m_head_tail;
        tmp = tmp->next)
        stream << tmp->value
        << (tmp->next == Liste.m_head_tail ? Liste.list_form.ende :
            Liste.list_form.zwischen);
    if (Liste.m_temp)
        delete& Liste; // wurde eine m_tempor�re Liste �bergeben, dann wird diese
                       // gel�scht
    return stream;
}
