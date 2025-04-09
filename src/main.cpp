#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

class $modify(GeoCheatsMenu, PauseLayer) {
    bool init() {
        if (!PauseLayer::init()) return false;

        auto menu = CCMenu::create();
        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto godModeBtn = CCMenuItemLabel::create(
            CCLabelBMFont::create("Toggle God Mode", "bigFont.fnt"),
            this,
            menu_selector(GeoCheatsMenu::onGodMode)
        );
        godModeBtn->setPosition({winSize.width / 2, winSize.height / 2});
        menu->addChild(godModeBtn);

        this->addChild(menu);
        return true;
    }

    void onGodMode(CCObject*) {
        Mod::get()->setSavedValue("god_mode", !Mod::get()->getSavedValue<bool>("god_mode"));
        FLAlertLayer::create("GeoCheats", Mod::get()->getSavedValue<bool>("god_mode") ? "God Mode: ON 🛡️" : "God Mode: OFF ☠️", "OK")->show();
    }
};
