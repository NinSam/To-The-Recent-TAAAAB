#include <Geode/Geode.hpp>
#include <random>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

int randomNumber(int min, int max) {
	static std::random_device rd;
    static std::mt19937 gen(rd());
	std::uniform_int_distribution<> distribution(min, max);

	return distribution(gen);
}

class $modify(LevelSearchLayer) {

	void onMostRecent(CCObject* sender){

		LevelSearchLayer::onMostRecent(sender);

		if (Mod::get()->getSettingValue<bool>("enable-voiceline")){

			auto setVoicelineConfig = Mod::get()->getSettingValue<std::string>("set-voiceline");

			if (Mod::get()->getSettingValue<bool>("fix-audio-overlap")){

				FMODAudioEngine::sharedEngine()->m_globalChannel->stop();
				FMODAudioEngine::sharedEngine()->m_system->update();
				
			}

			if (Mod::get()->getSettingValue<bool>("enable-set-voiceline")){

				if (setVoicelineConfig == "1/5"){
				FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab.ogg"_spr);
				}
				else if (setVoicelineConfig == "2/5"){
					FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_1.ogg"_spr);
				}
				else if (setVoicelineConfig == "3/5"){
					FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_2.ogg"_spr);
				}
				else if (setVoicelineConfig == "4/5"){
					FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_3.ogg"_spr);
				}
				else if (setVoicelineConfig == "5/5"){
					FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_4.ogg"_spr);
				}

			}
			else if (auto random = randomNumber(1, 5)){

				switch(random){
			
			    	case 1: FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab.ogg"_spr); break;

			    	case 2: FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_1.ogg"_spr); break;

			    	case 3: FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_2.ogg"_spr); break;

					case 4: FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_3.ogg"_spr); break;

			    	case 5: FMODAudioEngine::sharedEngine()->playEffect("evw_recent_tab_4.ogg"_spr); break;

					default: break;

	        	}

			}

		}

	}
};