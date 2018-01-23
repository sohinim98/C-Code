 #include <iostream>
 using namespace std;

 struct Data {
     int ID;
 };

 struct Stack {
     const Data* data;
     Stack* next;
 };

 bool push(Stack*& sp, const Data* d) {
     Stack* newNode = new Stack;
     if (newNode) {
         newNode->data = d;
         newNode->next = sp;
         sp = newNode;
         return true;
     }
     return false;
 }

 const Data* pop(Stack*& sp) {
     Stack* tmp = sp;
     const Data* retVal = 0;
     if (sp) {
         retVal = sp->data;
         sp = sp->next;
     }
     delete tmp;
     return retVal;
 }

  void displayStack(const Stack* sp) {
     const Stack* cur = sp;
     int i = 1;
     while (cur) {
         cout << i << ": " << cur->data->ID << " --> ";
         ++i;
         cur = cur->next;
     }
     cout << "EOS" << endl;
 }

  int main() {
     Data data[5];
     data[0].ID = 1;
     data[1].ID = 2;
     data[2].ID = 4;
     data[3].ID = 8;
     data[4].ID = 16;

     Stack* sp = 0;

	 cout << sp<< endl;
 }