#include <iostream>
#include <string>
#include <exception>
/*

public class User
{
    private const int AuthRetryCountLimit = 5;
    public string UserName { get; private set; }
    public bool AccountIsLocked { get; private set; }

    public bool Authenticate(string rawPassword, IPasswordEncryptor passwordEncryptor)
    {
        if (AccountIsLocked)
            throw new InvalidOperationException("User account is locked.");

        var hashedPassword = passwordEncryptor.EncryptPassword(rawPassword);

        if (_password == hashedPassword)
        {
            ResetAuthRetryAttempts();
            return true;
        }

        if (_password != hashedPassword)
            RegisterNewFailedAttempt();

        return false;
    }

    public void UnlockAccount()
    {
        if (!AccountIsLocked)
            return;

        AccountIsLocked = false;
        _authRetryCount = 0;
    }

    private void RegisterNewFailedAttempt()
    {
        _authRetryCount++;

        if (_authRetryCount == AuthRetryCountLimit)
        {
            AccountIsLocked = true;
        }
    }
    ...
}
*/

struct PasswordEncryptor
{
    std::string EncryptPassword(const std::string &password)
    {
        return password;
    }
};

class User
{
private:
    const int auth_retry_count_limit = 5;
    std::string user_name;
    std::string password;
    int auth_retry_count = 0;
    bool account_is_locked = false;
    void ResetAuthRetryAttempts(){ auth_retry_count =0;};

public:
    bool Authenticate(const std::string &raw_psassword, PasswordEncryptor &encryptor){
        if (account_is_locked)  throw std::logic_error("User account is locked.");
        std::string hashed_password = encryptor.EncryptPassword(raw_psassword);
        if (password == hashed_password){
            ResetAuthRetryAttempts();
            return true;
        }
        if (password != hashed_password) RegisterNewFailedAttempt();
        return false;
    }

    void UnlockAccount(){
        if (!account_is_locked) return;
        account_is_locked = false;
        auth_retry_count = 0;
    }

    void RegisterNewFailedAttempt(){
        auth_retry_count++;
        if (account_is_locked == auth_retry_count_limit) account_is_locked = true;
    }
};
auto main() -> int
{
    return 0;
}