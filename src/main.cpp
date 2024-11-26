#include <Geode/Geode.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(LevelSearchLayer) {
	
	void onMostRecent(CCObject* sender){

		LevelSearchLayer::onMostRecent(sender);
		if (Mod::get()->getSettingValue<bool>("enable-voiceline")){

			FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab.ogg"_spr);
		}
	}

	/*

	Idea from @Random_person921
	
	Uses music slider: FMODAudioEngine::sharedEngine()->playMusic();

	Uses sfx slider: FMODAudioEngine::sharedEngine()->playEffect();

	*/

};