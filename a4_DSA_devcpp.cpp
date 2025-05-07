//simple program to create ADT that implement the "set" concept. 
// a. Add (new Element) -Place a value into the set , b. Remove (element) Remove the 
// value 
// c. Contains (element) Return true if element is in collection, d. Size () Return number of 
// values in collection Iterator () Return an iterator used to loop over collection, e. 
// Intersection of two sets , f. Union of two sets, g. Difference between two sets, h. Subset

#include <iostream>
using namespace std;

class set{
    private:
    int cset[10];
    int count;

    public:
    set(){
        count = 0;
    }

    void addele(int a){
        if(count<10){
            cset[count++] = a;
        }
        else{
            cout<<"the set is full"<<endl;
        }
    }

    void remove(int a){
        int index =-1;
        for(int i = 0 ; i<count ;i++){
            if(cset[i]==a){
                index = i;
            }
        }
        if(index==-1){
            cout<<"the number is not present"<<endl;
        }

        for(int i = index ; i<count ; i++){
            cset[i] = cset[i+1];
        }
        count--;
    }

    void iterator(){
        for(int i = 0 ; i<count ; i++){
            cout<<cset[i]<<" ";
        }
    }

    int size(){
        return count;
    }

    bool contains(int a){
        for(int i = 0 ;i<count ; i++){
            if(cset[i]==a){
                return true;
            }
        }
        return false;

    }





    // void setunion(set oset , set &result){
    //     for(int i = 0 ; i<count ; i++){
    //         result.addele(cset[i]);
    //     }
    //     for(int j = 0;j<oset.count ; j++){
    //         int flag = -1;
    //         for(int i = 0; i<count ; i++){
    //             if(oset.cset[j] == cset[i]){
    //                 flag = 0;
    //                 break;
    //             }
    //         }
    //         if(flag ==-1){
    //             result.addele(oset.cset[j]);
    //         }
            
    //     }
    // }


    void setunion(set oset, set& result) {
    // Add elements from this set
    for (int i = 0; i < count; i++) {
        result.addele(cset[i]);
    }

    // Add elements from the other set if not already present
    for (int i = 0; i < oset.count; i++) {
        int flag = -1;  // Flag to check if the element already exists
        for (int j = 0; j < count; j++) {
            if (oset.cset[i] == cset[j]) {
                flag = 0;  // Element found, no need to add
                break;
            }
        }
        // If flag is still -1, it means the element is not present, so we add it
        if (flag == -1) {
            result.addele(oset.cset[i]);
        }
    }
}



    void inter(set oset ,set result){
        for(int j = 0 ; j<oset.count ; j++){
            int flag = 0;
            for(int i =0 ; i<count ; i++){
                if(oset.cset[j] == cset[i]){
                    flag = -1;
                    break;
                }
            }
            if(flag == -1){
                result.addele(oset.cset[j]);
            }
        }
    }

};
int main(){
    set s1,s2, result;
    int a,r,c;
    int n,n1;

     cout<<"enter number of elements you want to insert in set1"<<endl;
    cin>> n;
    cout<<"enter elements : "<<endl;
    for(int i = 0 ; i< n ; i++){
        cin>>a;
        s1.addele(a); 
    }
    cout<<"enter number of elements you want to insert in set2"<<endl;
    cin>> n1;
    cout<<"enter elements : "<<endl;
    for(int i = 0 ; i< n1 ; i++){
        cin>>a;
        s2.addele(a); 
    }
    cout<<"set 1:";
    s1.iterator();
    cout<<"\nset 2:";
    s2.iterator();

    cout<<"\nenter element to be removed from set 1";
    cin>>r;
    s1.remove(r);
    cout<<"\nset 1:";
    s1.iterator();

    cout<<"\nenter element to be removed from set 1";
    cin>>r;
    s2.remove(r);
    cout<<"\nset 1:";
    s2.iterator(); 

    cout<<"\nsize of set 1 : "<<s1.size();
    cout<<"\nsize of set 2 : "<<s2.size();

    cout<<"\nenter number you want to check for set 1 : "<<endl;
    cin>>c;
    if(s1.contains(a)){
        cout<<c<<" is present in set 1"<<endl;
    }
    else{
        cout<<c<<" is not present in set 1"<<endl;
    }
    cout<<"\nenter number you want to check for set 2 : "<<endl;
    cin>>c;
    if(s2.contains(a)){
        cout<<c<<" is present in set 2"<<endl;
    }
    else{
        cout<<c<<" is not present in set 2"<<endl;
    }

    s1.setunion(s2,result);
    cout<<"\nunion of set 1 and set 2 is : ";
    result.iterator();

    s1.inter(s2,result);
    cout<<"\nunion of set 1 and set 2 is : ";
    result.iterator();



    return 0;

} 