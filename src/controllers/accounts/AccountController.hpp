#pragma once

#include <QObject>

#include "controllers/accounts/Account.hpp"
#include "providers/twitch/TwitchAccountManager.hpp"
#include "util/SharedPtrElementLess.hpp"
#include "common/SignalVector2.hpp"

namespace chatterino {

class AccountModel;

class AccountController
{
public:
    AccountController();

    AccountModel *createModel(QObject *parent);

    void load();

    providers::twitch::TwitchAccountManager twitch;

private:
    util::SortedSignalVector<std::shared_ptr<Account>, util::SharedPtrElementLess<Account>>
        accounts;
};

}  // namespace chatterino
