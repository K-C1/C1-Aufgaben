class bankkonto 
{
    bool authenticated;
    float kontostand;
    const std::string pin;

  public:
    const std::string ec;
    const std::string account;
    bankkonto(std::string Konto, std::string Benutzer, std::string Passwort, float Betrag) : authenticated(false), account(Konto), ec(Benutzer), pin(Passwort), kontostand(Betrag)
    {
    }


    void printKontoinformationen()
    {
        std::cout << "*   Benutzername: " << ec << "\n*   PIN: " << pin << "\n*   Kontostand: " << kontostand << "\n* " << std::endl;
    }
    
    float getKontostand()
    {
        return kontostand;
    }

    void abhebenBetrag(float betrag)
    {
        kontostand -= betrag;
    }

    bool isRegistered(std::string EC)
    {
        if(EC == ec)
        {
            return true;
        }
    }
        
    bool isAuthenticated()
    {
        return authenticated;
    }

    bool login(std::string PIN)
    {
        if (PIN == pin)
        {
            authenticated = true;
        }
        else
        {
            authenticated = false;
        }
        return authenticated;
    }

    void logout()
    {
        authenticated = false;
    }
};
