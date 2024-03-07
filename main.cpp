#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ranges>

struct ChristmasWish{
    std::string Name;
    int Price;
    ChristmasWish(std::string name, int price){
        Name = name;
        Price = price;
    }        
};


class Movie{
public:
    typedef enum {
        MovieType_Film,
        MovieType_Tv
    }MovieType;

    Movie(){

    }

    Movie(std::string name, int year,MovieType type, int price)
    :name(name),year(year),type(type),price(price){
    }
    std::string getName() const{
        return name;
    }
    int getYear() const{
        return year;
    }
    int getPrice() const{
        return price;
    }
    MovieType getMovieType() const{
        return type;
    }
private:
    std::string name;
    MovieType type;
    int year;
    int price;
};

// C++ 20 
// coolest thing ever in C++ = views 




template<typename T>
T largestOfThree(T i, T j, T k){
    if(i > j && i > k){
        return i;
    }
    if(j > i && j > k){
        return j;
    }
    return k;
}

template<typename T, int size>
class MySuperDuperArray{
public:    
private:
    T arrayen[size];
};



int main(){
    MySuperDuperArray<int,10> hej;
    MySuperDuperArray<float,15> hej2;
    MySuperDuperArray<Movie,100> movies;


    int a = largestOfThree(12,34,56);
    float f = largestOfThree(12.11f,34.22f,56.123f);
    std::string l = largestOfThree<std::string>("Stefan","asdasd","234234342");
    std::vector<Movie> greatMovies{
        Movie("The Mummy returns",2022,Movie::MovieType::MovieType_Film,40), // <- begin
        Movie("Fast and Furious 7",2014,Movie::MovieType::MovieType_Film,99),  // <-items
        Movie("Star Trek: Voyager",2000,Movie::MovieType::MovieType_Tv,50),
        Movie("Fast & Furious Presents: Hobbs & Shaw",2019,Movie::MovieType::MovieType_Film,88),
       Movie("Young Rock",2021,Movie::MovieType::MovieType_Tv,82),
    };    
    

    // auto result2 = greatMovies | std::views::filter([](const Movie &m){
    //     std::cout << "In filter" << std::endl;
    //     return m.getPrice() < 90;
    // }) | std::views::transform([](const Movie &m){
    //       return ChristmasWish(m.getName(), m.getPrice());
    // });
    // for(auto wish: result2){
    //     std::cout << wish.Name << std::endl;
    // }





    // std::ranges::sort(greatMovies,[](const Movie &item1, const Movie &item2){
    //     return item1.getPrice() < item2.getPrice();        
    // });


    std::sort(std::begin(greatMovies),std::end(greatMovies),[](const Movie &item1, const Movie &item2){
        return item1.getPrice() < item2.getPrice();        
    });
    for(auto &m : greatMovies ){
        std::cout << m.getName() << std::endl;
    }

    // Ta fram och skriv ut alla som kostar mindre än 90 kr
    auto i = std::begin(greatMovies),end = std::end(greatMovies);
    while(i != end){
        i = std::find_if(i,end,[](auto const &m){
            return m.getPrice() < 90;
        });
        // hello
        if(i != end){
            std::cout << i->getName() << std::endl;
            //i = std::next(i);
            i++;
        }
    }    


    // bool any2000 = std::ranges::any_of(greatMovies,[](const Movie &m){
    //     return m.getYear() == 2000;
    // });


    // Finns det nån film som är gjord år 2000
    bool any2000 = std::any_of(std::begin(greatMovies),std::end(greatMovies),[](const Movie &m){
        return m.getYear() == 2000;
    });
    // bool any2000 = false;
    // for(const Movie  &m : greatMovies)
    //     if(m.getYear() == 2000){
    //         any2000 = true;
    //         break;
    //     }
    // }

    // for(int i = 0; i < greatMovies.size();i++){
    //     if(greatMovies[i].getYear() == 2000){
    //         any2000 = true;
    //         break;
    //     }
    // }
    // if(any2000) {
    //     std::cout << "Yes" << std::endl;
    // }



    //Hur många filmer kostar > 60 kr
    // int count = 0;
    // for(int i = 0; i < greatMovies.size();i++){
    //     if(greatMovies[i].getPrice() > 60){
    //         count++;
    //     }
    // }
    int count = std::count_if(std::begin(greatMovies), std::end(greatMovies),[](const Movie &m){
        return m.getPrice() > 60;
    });

    // int total = 0;
    // for(int i = 0; i < greatMovies.size();i++){
    //     total += greatMovies[i].getPrice();
    // }

    // int total = std::accumulate(std::begin(greatMovies),std::end(greatMovies),0,[](int sum, const Movie &m){
    //         return sum + m.getPrice();
    //     });


        // if(m.getPrice() > 60)
        //     return true;
        // return false;

    std::cout << "Antal: " << count << std::endl;
     






}