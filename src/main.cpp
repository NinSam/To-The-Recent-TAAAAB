#include <Geode/Geode.hpp>
#include <ctime>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(LevelSearchLayer) {
	
	void onMostRecent(CCObject* sender){

		LevelSearchLayer::onMostRecent(sender);

		if (Mod::get()->getSettingValue<bool>("enable-voiceline")){

			if (Mod::get()->getSettingValue<bool>("fix-audio-overlap")){

				FMODAudioEngine::sharedEngine()->m_globalChannel->stop();
				FMODAudioEngine::sharedEngine()->m_system->update();
				
			}

		    srand(time(nullptr));
		    int random = rand() % 3 + 1;

		    switch(random){
			
			    case 1: FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab.ogg"_spr);

			    break;

			    case 2: FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_1.ogg"_spr);

			    break;

			    case 3: FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_2.ogg"_spr);

			    break;

	        }

		}

	}
};