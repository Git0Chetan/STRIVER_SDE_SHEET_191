//implementation of heap

#include<iostream>
using namespace std;

class heap{
    vector<int>v;
    int l(int parent);
    int r(int parent);
    int par(int child);
    void heapifyup(int index);
    void heapifydn(int index);

    public:
    heap(){}
    void insert(int a);
    void delet();
    int extract();
    void show();
    int size();
};

void heap::insert(int a){
    v.push_back(a);
    heapifyup(v.size()-1);
}

void heap::delet(){
    if(v.size()==0){
        return;
    }
    v[0]=v[v.size()-1];
    v.pop_back();
    heapifydn(0);
}

int heap::extract(){
    if(v.size()==0){
        return -1;
    }
    return v.front();
}

void heap::show(){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\t";
    }
    cout<<endl;
}

int heap::size(){
    return v.size();
}

int heap::l(int parent){
    int a=2*parent +1;
    if(a<v.size()){
        return a;
    }
    return -1;
}

int heap::r(int parent){
    int a=2*parent +2;
    if(a<v.size()){
        return a;
    }
    return -1;
}

int heap::par(int child) {
   int p = (child - 1)/2;
   if (child == 0)
      return -1;
   else
      return p;
}

void heap::heapifyup(int in) {
   if (in >= 0 && par(in) >= 0 && v[par(in)] > v[in]) {
      int temp = v[in];
      v[in] = v[par(in)];
      v[par(in)] = temp;
      heapifyup(par(in));
   }
}

void heap:: heapifydn(int a){
    int c1=l(a);
    int c2=r(a);

    if(c1>=0 && c2>=0 && v[c1]>v[c2]){
        c1=c2;
    }

    if(c1>=0 && v[a]>v[c1]){
        swap(v[c1],v[a]);
        heapifydn(c1);
    }
}


int main(){
    heap h;
    h.insert(5);
    h.insert(6);
    h.insert(1);
    h.insert(8);
    h.show();
    cout<<h.extract()<<endl;
    h.delet();
    h.show();
}