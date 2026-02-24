#include <Geode/loader/SettingV3.hpp>

using namespace geode::prelude;

class SetVoicelineSetting : public SettingV3{
public:
    static Result<std::shared_ptr<SettingV3>> parse(std::string const& key, std::string const& modID, matjson::Value const& json){
        auto res = std::make_shared<SetVoicelineSetting>();
        auto root = checkJson(json, "set-voiceline-audio");
        res->init(key, modID, root);
        res->parseNameAndDescription(root);
        res->parseEnableIf(root);
        root.checkUnknownKeys();

        return root.ok(std::static_pointer_cast<SettingV3>(res));
    }

    bool load(matjson::Value const& json) override{
        return true;
    }

    bool save(matjson::Value& json) const override{
        return true;
    }

    bool isDefaultValue() const override{
        return true;
    }

    void reset() override {}

    SettingNodeV3* createNode(float width) override;
};

class SetVoicelineSettingNode : public SettingNodeV3{
protected:
    CCMenuItemSpriteExtra* m_button;
    CCMenuItemSpriteExtra* m_button1;
    CCMenuItemSpriteExtra* m_button2;
    CCMenuItemSpriteExtra* m_button3;
    CCMenuItemSpriteExtra* m_button4;

    bool init(std::shared_ptr<SetVoicelineSetting> setting, float width){
        if (!SettingNodeV3::init(setting, width))
        return false;

        this->setContentHeight(50);

        auto screenSize = CCDirector::sharedDirector()->getWinSize();

        auto sprite = CCSprite::createWithSpriteFrameName("GJ_playMusicBtn_001.png");
        sprite->setScale(0.6f);

        auto label = CCLabelBMFont::create("1", "bigFont.fnt");
        auto label1 = CCLabelBMFont::create("2", "bigFont.fnt");
        auto label2 = CCLabelBMFont::create("3", "bigFont.fnt");
        auto label3 = CCLabelBMFont::create("4", "bigFont.fnt");
        auto label4 = CCLabelBMFont::create("5", "bigFont.fnt");

        label->setScale(0.4f);
        label1->setScale(0.4f);
        label2->setScale(0.4f);
        label3->setScale(0.4f);
        label4->setScale(0.4f);
    
        m_button = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(SetVoicelineSettingNode::onAudio1));
        m_button1 = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(SetVoicelineSettingNode::onAudio2));
        m_button2 = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(SetVoicelineSettingNode::onAudio3));
        m_button3 = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(SetVoicelineSettingNode::onAudio4));
        m_button4 = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(SetVoicelineSettingNode::onAudio5));


        this->getButtonMenu()->addChildAtPosition(m_button, Anchor::Center, CCPoint{-55,-7});
        this->getButtonMenu()->addChildAtPosition(m_button1, Anchor::Center, CCPoint{-22,-7});
        this->getButtonMenu()->addChildAtPosition(m_button2, Anchor::Center, CCPoint{11,-7});
        this->getButtonMenu()->addChildAtPosition(m_button3, Anchor::Center, CCPoint{44,-7});
        this->getButtonMenu()->addChildAtPosition(m_button4, Anchor::Center, CCPoint{77,-7});

        this->getButtonMenu()->addChildAtPosition(label, Anchor::Center, CCPoint{-55,14});
        this->getButtonMenu()->addChildAtPosition(label1, Anchor::Center, CCPoint{-22,14});
        this->getButtonMenu()->addChildAtPosition(label2, Anchor::Center, CCPoint{11,14});
        this->getButtonMenu()->addChildAtPosition(label3, Anchor::Center, CCPoint{44,14});
        this->getButtonMenu()->addChildAtPosition(label4, Anchor::Center, CCPoint{77,14});

        this->getButtonMenu()->setContentWidth(180);
        this->getButtonMenu()->updateLayout();

        this->updateState(nullptr);
        
        return true;
    }
    
    void updateState(CCNode* invoker) override{
        SettingNodeV3::updateState(invoker);

        auto shouldEnable = this->getSetting()->shouldEnable();

        m_button->setEnabled(shouldEnable);
        m_button1->setEnabled(shouldEnable);
        m_button2->setEnabled(shouldEnable);
        m_button3->setEnabled(shouldEnable);
        m_button4->setEnabled(shouldEnable);

        m_button->setCascadeColorEnabled(true);
        m_button->setCascadeOpacityEnabled(true);
        m_button->setOpacity(shouldEnable ? 255 : 155);
        m_button->setColor(shouldEnable ? ccWHITE : ccGRAY);

        m_button1->setCascadeColorEnabled(true);
        m_button1->setCascadeOpacityEnabled(true);
        m_button1->setOpacity(shouldEnable ? 255 : 155);
        m_button1->setColor(shouldEnable ? ccWHITE : ccGRAY);

        m_button2->setCascadeColorEnabled(true);
        m_button2->setCascadeOpacityEnabled(true);
        m_button2->setOpacity(shouldEnable ? 255 : 155);
        m_button2->setColor(shouldEnable ? ccWHITE : ccGRAY);

        m_button3->setCascadeColorEnabled(true);
        m_button3->setCascadeOpacityEnabled(true);
        m_button3->setOpacity(shouldEnable ? 255 : 155);
        m_button3->setColor(shouldEnable ? ccWHITE : ccGRAY);

        m_button4->setCascadeColorEnabled(true);
        m_button4->setCascadeOpacityEnabled(true);
        m_button4->setOpacity(shouldEnable ? 255 : 155);
        m_button4->setColor(shouldEnable ? ccWHITE : ccGRAY);

    }

    void onAudio1(CCObject*){

        FMODAudioEngine::sharedEngine()->m_globalChannel->stop();
		FMODAudioEngine::sharedEngine()->m_system->update();
        FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab.ogg"_spr);
        
    }

    void onAudio2(CCObject*){

        FMODAudioEngine::sharedEngine()->m_globalChannel->stop();
		FMODAudioEngine::sharedEngine()->m_system->update();
        FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_1.ogg"_spr);
        
    }

    void onAudio3(CCObject*){

        FMODAudioEngine::sharedEngine()->m_globalChannel->stop();
		FMODAudioEngine::sharedEngine()->m_system->update();
        FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_2.ogg"_spr);
        
    }

    void onAudio4(CCObject*){

        FMODAudioEngine::sharedEngine()->m_globalChannel->stop();
		FMODAudioEngine::sharedEngine()->m_system->update();
        FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_3.ogg"_spr);
        
    }

    void onAudio5(CCObject*){

        FMODAudioEngine::sharedEngine()->m_globalChannel->stop();
		FMODAudioEngine::sharedEngine()->m_system->update();
        FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_4.ogg"_spr);
        
    }

    void onCommit() override {}
    void onResetToDefault() override {}

public:
    static SetVoicelineSettingNode* create(std::shared_ptr<SetVoicelineSetting> setting, float width){
        auto ret = new SetVoicelineSettingNode();
        if (ret && ret->init(setting, width)){
            ret->autorelease();
            return ret;
        }
        delete ret;
        return nullptr;
    }

    bool hasUncommittedChanges() const override{
        return false;
    }

    bool hasNonDefaultValue() const override{
        return false;
    }

    std::shared_ptr<SetVoicelineSetting> getSetting() const{
        return std::static_pointer_cast<SetVoicelineSetting>(SettingNodeV3::getSetting());
    }
};

SettingNodeV3* SetVoicelineSetting::createNode(float width){
    return SetVoicelineSettingNode::create(
        std::static_pointer_cast<SetVoicelineSetting>(shared_from_this()),
        width
    );
}

$execute{
    (void)Mod::get()->registerCustomSettingType("set-voiceline-audio", &SetVoicelineSetting::parse);
}