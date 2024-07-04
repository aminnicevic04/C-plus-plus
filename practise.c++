#include <iostream>
#include <list>
#include <string>

using namespace std;

class YouTubeChannel {
    //ovde smo napravili private ovo iz razloga da bi ga iskoristili u klasi a metode u kojima koristimo napravili smo public i onda njih upotrebljavali izvan klase i ovo se naziva Enkapsulacija
    private: 
        string Name;
        int SubscribersCount;
        list<string> PublishedVideoTitles; 
    protected:
        string OwnerName;
        int ContentQuality;
    public:
        YouTubeChannel(string name, string ownerName){ //constructor
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        ContentQuality = 0;
    } 
    void GetInfo(){ //class method  *Getter*
    cout << "Name: " << Name << endl;
    cout << "Owner Name: " << OwnerName << endl;
    cout << "Subscribers: " << SubscribersCount << endl;
    cout << "Videos:" << endl;
    
        for (string videoTitle: PublishedVideoTitles) {
            cout << videoTitle << endl;
        }
    }
    void Subscribe(){ // *Setter*
        SubscribersCount++;
    }
    void UnSubscribe(){ // *Setter*
        if(SubscribersCount > 0)
        SubscribersCount--;
    }
    void PublishVideo(string title){ // *Setter*
        PublishedVideoTitles.push_back(title);
    }
    void CheckAnalitics(){
        if(ContentQuality<5){
            cout<< Name<<" has a bad quality content."<<endl ; 
        }else{
            cout<< Name<<" has a good quality content."<<endl ;
        }
    }
};

class CookingYoutubeChannel:public YouTubeChannel{
    public:
    CookingYoutubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName){
    }
    void Practise(){
        cout << OwnerName <<  " Practise" << endl;
        ContentQuality++;
    }
};
class SingersYoutubeChannel:public YouTubeChannel{
    public:
    SingersYoutubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName){
    }
    void Practise() {
        cout << OwnerName <<  " Practise num. 2" << endl;
        ContentQuality++; 
    }
};

int main() {
    
    CookingYoutubeChannel cookingYtChannel("Amci kuvar", "Amci");
    CookingYoutubeChannel singersYtChannel("Smelto pevac", "Smelto");


    cookingYtChannel.Practise();
    singersYtChannel.Practise();
    singersYtChannel.Practise();
    singersYtChannel.Practise();
    singersYtChannel.Practise();
    singersYtChannel.Practise();
    singersYtChannel.Practise();

    YouTubeChannel * yt1 = &cookingYtChannel;
    YouTubeChannel * yt2 = &singersYtChannel;

    yt1->CheckAnalitics();
    yt2->CheckAnalitics();
    
   
    system("pause>0");
    return 0;
}
