#include <iostream>
#include <string>
#include <exception>

struct Tenant {};
struct Author {
    Author(const Tenant&,const std::string &) {}
};
struct CollaboratorService{};


struct TranslatingCollaboratorService : CollaboratorService
{
    Author authorFrom(Tenant aTenant, const std::string&  anIdentity)
    {
        return Author(aTenant,anIdentity);
    }
};

auto main() -> int
{
    return 0;
}