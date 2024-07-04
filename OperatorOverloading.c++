#include <iostream>
#include <string>
#include <list>
using namespace std;

struct YoutubeChannel{
    string Name;
    int SubscribersCount;

    YoutubeChannel(string name, int subscribersCount){
        Name = name;
        SubscribersCount = subscribersCount; 
    }

    bool operator==(const YoutubeChannel& channel) const {
        return this->Name == channel.Name;
    }
};

ostream& operator<<(ostream& COUT, const YoutubeChannel& ytChannel){ 
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;
    return COUT;
}

struct MyCollection{
    list<YoutubeChannel> myChannels;

    void operator+=(const YoutubeChannel& channel){
        this->myChannels.push_back(channel);
    }
    void operator-=(const YoutubeChannel& channel){
        this->myChannels.remove(channel);
    }
};

ostream& operator<<(ostream& COUT, const MyCollection& myCollection){
    for (const YoutubeChannel& ytChannel : myCollection.myChannels) {
        COUT << ytChannel << endl;
    }
    return COUT;
}

int main(){
    YoutubeChannel yt1 = YoutubeChannel("Amcijev YT",  10240);
    YoutubeChannel yt2 = YoutubeChannel("Amcijev DRUGI YT",  100);

    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2;
    cout << myCollection;

    cin.get();
}
