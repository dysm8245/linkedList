/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represent communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"

using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork() {
    // TODO: Copy your definition for constructor here
    head = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty() {
    // TODO: Copy your definition for isEmpty here
    if(head == NULL){
        return 1;
    }
    return 0;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    // TODO: Copy your definition for insertCountry here
    Country *left = previous;
    Country *node = new Country;
    node->name = countryName;
    if(left == NULL){
        node->next = head;
        head = node;
        // If you are adding at the beginning use this:
        cout << "adding: " << countryName << " (HEAD)" << endl;
    }
    else if(left->next == NULL){
        left->next = node;
        left = node;
        cout << "adding: " << countryName << " (prev: " << previous->name << 
        ")" << endl;
    }
    else{
        node->next = left->next;
        left->next = node;
        // Otherwise use this:
        cout << "adding: " << countryName << " (prev: " << previous->name << 
        ")" << endl;
    }
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName)
{
    // TODO: Copy your definition for deleteCountry
    Country *node;
    node = searchNetwork(countryName);
    if(node == NULL){
        cout << "Country does not exist." << endl;
    }
    else{
        if(head->name == countryName){
            Country *temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Country *left = head;
            Country *temp = left->next;
            bool isFound = false;
            while(temp!= 0 && isFound!= true){
                if (temp->name == countryName){
                    if (temp->next == 0){
                        left->next = 0;

                    }
                    else{
                        left->next = temp->next;
                    }
                    delete temp;
                    isFound = true;
                }
                else{
                    left = temp;
                    temp = temp->next;
                }
            }
        }
    }
}

/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup() 
{
    // TODO: Copy your definition for loadDefaultSetup here
    Country *node = new Country;
    node = searchNetwork("United States");
    insertCountry(node,"United States");
    Country *node1 = new Country;
    node1 = searchNetwork("United States");
    insertCountry(node1,"Canada");
    Country *node2 = new Country;
    node2 = searchNetwork("Canada");
    insertCountry(node2,"Brazil");
    Country *node3 = new Country;
    node3 = searchNetwork("Brazil");
    insertCountry(node3,"India");
    Country *node4 = new Country;
    node4 = searchNetwork("India");
    insertCountry(node4,"China");
    Country *node5 = new Country;
    node5 = searchNetwork("China");
    insertCountry(node5,"Australia");
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    // TODO: Copy your definition for searchNetwork here
    Country *current = head;
    while(current != NULL){
        if(current->name == countryName){
            return current;
        }
        current = current->next;
    }
    return current;
}

/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    // TODO: Copy your definition for deleteEntireNetwork
    Country *current;
    while(head != NULL){
        current = head->next;
        cout << "deleting: " << head->name << endl;
        delete head;
        head = current;
    }
    cout << "Deleted network" << endl;
}

/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    // TODO: Copy your definition for transmitMsg here
    if(isEmpty()==1){
        cout << "Empty List" << endl;
    }
    else{
        Country *current = head;
        if(searchNetwork(receiver) != 0){
            while(current->name != receiver){
                current->message = message;
                current->numberMessages += 1;
                cout << current->name << " [# messages received: " << current->numberMessages << 
                "] received: " << current->message << endl;
                current = current->next;
            }
            current->message = message;
            current->numberMessages += 1;
            cout << current->name << " [# messages received: " << current->numberMessages << 
            "] received: " << current->message << endl;
        }
        else{
            cout << "Country not found" << endl;
        }
    }
}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    // TODO: Copy your definition for printPath
    if(isEmpty()==1){
        cout << "== CURRENT PATH ==" << endl;
        cout << "nothing in path" << endl;
        cout << "===" << endl;
    }
    else{
        Country *current = head;
        cout << "== CURRENT PATH ==" << endl;
        while(current != NULL){
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl; 
        cout << "===" << endl;
    }
    
}
