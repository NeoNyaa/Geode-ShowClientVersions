#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
  bool init() {
    if (!MenuLayer::init()) return false;

    auto confPos = Mod::get()->getSettingValue<std::string>("version-position");
    auto confOpacity = Mod::get()->getSettingValue<double>("version-opacity");
    auto confDebug = Mod::get()->getSettingValue<bool>("debug-enabled");

    // Got some help in DMs with this, cpp really isnt that intuitive to me.
    auto curGDVer = Loader::get()->getGameVersion();
    auto curGeodeVer = Loader::get()->getVersion().toNonVString();
    auto labelString = "GD: v" + curGDVer + " (Geode: v" + curGeodeVer + ")";
    auto labelItem = CCLabelBMFont::create(labelString.c_str(), "bigFont.fnt");

    auto menuHeight = getContentHeight();
    auto menuWidth = getContentWidth();

    // Here for making sure I actually got what values I wanted
    if (confDebug == true) {
      log::info("Position: {}", confPos);
      log::info("Main Menu Height: {}", menuHeight);
      log::info("Main Menu Width: {}", menuWidth);
      log::info("Opacity: {}", confOpacity);
      log::info("Game Version: {}", curGDVer);
      log::info("Geode Version: {}", curGeodeVer);
    }

    // There is probably a better way of implementing this but it works and doesnt look that bad (at least to me)
    if (confPos == "Top Left") {
      labelItem->setPosition(0, menuHeight);
      labelItem->setAnchorPoint({-0.05f, 1.05f});
    }
    if (confPos == "Top Right") {
      labelItem->setPosition(menuWidth, menuHeight);
      labelItem->setAnchorPoint({1.05f, 1.05f});
    }
    if (confPos == "Bottom Left") {
      labelItem->setPosition(0, 0);
      labelItem->setAnchorPoint({-0.05f, -0.2f});
    }
    if (confPos == "Bottom Right") {
      labelItem->setPosition(menuWidth, 0);
      labelItem->setAnchorPoint({1.05f, -0.2f});
    }

    labelItem->setScale(0.25f);
    labelItem->setOpacity(confOpacity);
    labelItem->setID("game-version-label");
    this->addChild(labelItem);
    return true;
  }
};
