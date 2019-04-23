#include<stdio.h>
#include"linkedlist.h"
#include"util.h"
#include"tree.h"

int main() {
	Date *d;
	d = createDate(1970, 12, 1);

	Medicine *m;
	m = createMedicine("XYZ", 34.5, d, createDate(2018, 12, 2));

    Contact_Details *Cd = createContact("Shreyansh", 9838177556, "chouhan.shreyansh630@gmail.com", "address");
    Receipt *rec = createReceipt(0, m, d, 10, Cd, 0, 1);
    Receipt *rec2= createReceipt(0, m, d, 12, Cd, 0, 1);
 
    LinkedList *recs = createLinkedList();
    addNode(recs, createNode(rec));
    addNode(recs, createNode(rec2));
    Level lvl = DISTRIBUTOR;

    Vertex *v1 = createVertex(1, SHOP, createLinkedList(), createLinkedList(), recs, createLinkedList(), createLinkedList());
    Vertex *v2 = createVertex(2, SHOP, createLinkedList(), createLinkedList(), recs, createLinkedList(), createLinkedList());
    Vertex *v3 = createVertex(3, SHOP, createLinkedList(), createLinkedList(), recs, createLinkedList(), createLinkedList());

    LinkedList *children = createLinkedList();
    addNode(children, createNode(v1));
    addNode(children, createNode(v2));
    addNode(children, createNode(v3));

    Vertex *v = createVertex(0, MANUFACTURER, createLinkedList(), createLinkedList(), recs, createLinkedList(), children);

    Vertex *vf = findVertex(v, 1);
    printVertex(vf);
	return 0;
}
