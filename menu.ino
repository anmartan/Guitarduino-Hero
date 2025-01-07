class Menu 
{
public:
    struct songInfo
    {
        std::string name = "";
        int highScore = 0;
    };
    songInfo songs[5];  // poner aqui las que sean
    int sizeOfArray;    // solo para no estar haciendo sizeof todo el rato    
    int songDisplayed;  // indice de la que se esta mostrando 

    Menu()
    {
        songs[0] = { "primera", 50 };
        songs[1] = { "segunda", 150 };
        songs[2] = { "tercera", 250 };
        songs[3] = { "cuarta", 520 };
        songs[4] = { "quinta", 350 };
        songDisplayed = 0;
        sizeOfArray = sizeof(songs) / sizeof(songInfo);
    }

    void move(bool next)
    {
        if (next) songDisplayed = (songDisplayed + 1) % sizeOfArray;
        else 
        {
            if (songDisplayed <= 0) songDisplayed = sizeOfArray;
            songDisplayed--;
        }
    }

    void show()
    {
        std::cout << songs[songDisplayed].name << "   " << songs[songDisplayed].highScore << "\n";
    }

    void update(int score)
    {
        if (score > songs[songDisplayed].highScore)
            songs[songDisplayed].highScore = score;
    }

    songInfo select() 
    {
        return songs[songDisplayed];
    }

};

void setup()
{

}

void loop()
{
  
}

static std::string getAnswer()
{
    std::string answer;
    std::cin >> answer;
    return answer;
}

int main()
{
    Menu menu;
    Menu::songInfo chosenSong;

    while (true)
    {
        menu.show();
        std::chrono::seconds timeout(2);

        std::string answer = "n"; //default to maybe
        std::future<std::string> future = std::async(getAnswer);
        if (future.wait_for(timeout) == std::future_status::ready)
        {
            answer = future.get();
            if (answer == "a") menu.move(true);
            else if (answer == "s") menu.move(false);
            else if (answer == "q") 
            {
                chosenSong = menu.select();
                break;
            }

        }
    }

    std::cout << "Chosen song was: " << chosenSong.name;
}
