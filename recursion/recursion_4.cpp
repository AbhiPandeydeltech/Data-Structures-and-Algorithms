#include <iostream>
using namespace std;

void print_no_passed_in_words(int n,string* arr){
      
      if(n==0)
      return ;
      print_no_passed_in_words(n/10,arr);
      cout<<arr[n%10]<<" ";
}

int main(){
    string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};

    int n;
    cout<<"Enter the number : ";
    cin>>n;

    print_no_passed_in_words(n,arr);

    return 0;
}