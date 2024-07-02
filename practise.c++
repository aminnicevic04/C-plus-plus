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

    public:
        YouTubeChannel(string name, string ownerName){ //constructor
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
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
};

class CookingYoutubeChannel:public YouTubeChannel{
    public:
    CookingYoutubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName){
        
    }
    void Practise(){
        cout << OwnerName <<  " Practise" << endl;
    }
};

int main() {
    
    CookingYoutubeChannel drugiytChannel("Amcijev YT", "Amci");
    CookingYoutubeChannel drugiytChannel2("Smeltov YT", "Smelto");

    // drugiytChannel.PublishVideo("video1");
    // drugiytChannel.PublishVideo("video2");
    // drugiytChannel.Subscribe();
    // drugiytChannel.Subscribe();
    // drugiytChannel.GetInfo();

    drugiytChannel.Practise();

    drugiytChannel2.Practise();
    
   
    system("pause>0");
    return 0;
}
