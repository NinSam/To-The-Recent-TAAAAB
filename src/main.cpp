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

	from here: https://www.youtube.com/watch?v=khNOxO_uq80&t=25s
	
	Uses music slider: FMODAudioEngine::sharedEngine()->playMusic();

	Uses sfx slider: FMODAudioEngine::sharedEngine()->playEffect();




    Get bool setting: Mod::get()->getSettingValue<bool>("")

	Get int setting: Mod::get()->getSettingValue<int64_t>("") == 0
	

	*/

};