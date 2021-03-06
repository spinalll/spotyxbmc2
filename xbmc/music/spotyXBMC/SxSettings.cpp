/*
 spotyxbmc2 - A project to integrate Spotify into XBMC
 Copyright (C) 2011  David Erenger

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 For contact with the author:
 david.erenger@gmail.com
 */

#include "SxSettings.h"
#include "URL.h"

namespace addon_music_spotify {

  Settings::Settings() {
  }

  Settings::~Settings() {
  }

  CStdString Settings::getCachePath() {
    return CSpecialProtocol::TranslatePath("special://temp/spotify/cache/");
  }

  CStdString Settings::getThumbPath() {
	return CSpecialProtocol::TranslatePath("special://temp/spotify/thumbs/");
  }

  CStdString Settings::getArtistThumbPath() {
	return CSpecialProtocol::TranslatePath("special://temp/spotify/artistthumbs/");
  }

  int Settings::getArtistNumberArtists() {
    int i = atoi(getAddonSetting("artistNoArtists")) + 1;
    if (i == 11) return -1;
    return 10 * i;
  }

  int Settings::getArtistNumberAlbums() {
    int i = atoi(getAddonSetting("artistNoAlbums")) + 1;
    if (i == 11) return -1;
    return 10 * i;
  }

  int Settings::getArtistNumberTracks() {
    int i = atoi(getAddonSetting("artistNoTracks")) + 1;
    if (i == 11) return -1;
    return 10 * i;
  }

  CStdString Settings::getFanart() {
    ADDON::AddonPtr addon;
    const CStdString pluginId = "plugin.music.spotyXBMC";
    CStdString fanart = "";

    if (ADDON::CAddonMgr::Get().GetAddon(pluginId, addon)) {
      if (getAddonSetting("enablefanart") == "true"){
        if (getAddonSetting("customfanart") == "true"){
          fanart = getAddonSetting("fanart");
        }else{
          fanart = addon->FanArt();
        }
      }
    }
    return fanart;
  }

  sp_radio_genre Settings::getRadio1Genres() {

    struct {
      bool enable;
      int id;
    } radiogenres[] = {
    		{ getAddonSetting("radio1genre1") == "true", 0x1 },
    		{ getAddonSetting("radio1genre2") == "true", 0x2 },
    		{ getAddonSetting("radio1genre3") == "true", 0x4 },
    		{ getAddonSetting("radio1genre4") == "true", 0x8 },
    		{ getAddonSetting("radio1genre5") == "true", 0x10 },
    		{ getAddonSetting("radio1genre6") == "true", 0x20 },
    		{ getAddonSetting("radio1genre7") == "true", 0x40 },
    		{ getAddonSetting("radio1genre8") == "true", 0x80 },
    		{ getAddonSetting("radio1genre9") == "true", 0x100 },
    		{ getAddonSetting("radio1genre10") == "true", 0x200 },
    		{ getAddonSetting("radio1genre11") == "true", 0x400 },
    		{ getAddonSetting("radio1genre12") == "true", 0x800 },
    		{ getAddonSetting("radio1genre13") == "true", 0x1000 },
    		{ getAddonSetting("radio1genre14") == "true", 0x2000 },
    		{ getAddonSetting("radio1genre15") == "true", 0x4000 },
    		{ getAddonSetting("radio1genre16") == "true", 0x8000 },
    		{ getAddonSetting("radio1genre17") == "true", 0x10000 },
    		{ getAddonSetting("radio1genre18") == "true", 0x20000 }, 
			{ getAddonSetting("radio1genre19") == "true", 0x40000 },
    		{ getAddonSetting("radio1genre20") == "true", 0x80000 },
    		{ getAddonSetting("radio1genre21") == "true", 0x100000 },
    		{ getAddonSetting("radio1genre22") == "true", 0x200000 },
    		{ getAddonSetting("radio1genre23") == "true", 0x400000 },
    		{ getAddonSetting("radio1genre24") == "true", 0x800000 },
    		{ getAddonSetting("radio1genre25") == "true", 0x1000000 },
    		{ getAddonSetting("radio1genre26") == "true", 0x2000000 },
    		{ getAddonSetting("radio1genre27") == "true", 0x4000000 }, };

    int mask = 0;
    for (int i = 0; i < sizeof(radiogenres) / sizeof(radiogenres[0]); i++)
      if (radiogenres[i].enable) mask |= radiogenres[i].id;

    return (sp_radio_genre) mask;
  }

  sp_radio_genre Settings::getRadio2Genres() {

    struct {
      bool enable;
      int id;
    }radiogenres[] = {
    		{ getAddonSetting("radio2genre1") == "true", 0x1 },
    		{ getAddonSetting("radio2genre2") == "true", 0x2 },
    		{ getAddonSetting("radio2genre3") == "true", 0x4 },
    		{ getAddonSetting("radio2genre4") == "true", 0x8 },
    		{ getAddonSetting("radio2genre5") == "true", 0x10 },
    		{ getAddonSetting("radio2genre6") == "true", 0x20 },
    		{ getAddonSetting("radio2genre7") == "true", 0x40 },
    		{ getAddonSetting("radio2genre8") == "true", 0x80 },
    		{ getAddonSetting("radio2genre9") == "true", 0x100 },
    		{ getAddonSetting("radio2genre10") == "true", 0x200 },
    		{ getAddonSetting("radio2genre11") == "true", 0x400 },
    		{ getAddonSetting("radio2genre12") == "true", 0x800 },
    		{ getAddonSetting("radio2genre13") == "true", 0x1000 },
    		{ getAddonSetting("radio2genre14") == "true", 0x2000 },
    		{ getAddonSetting("radio2genre15") == "true", 0x4000 },
    		{ getAddonSetting("radio2genre16") == "true", 0x8000 },
    		{ getAddonSetting("radio2genre17") == "true", 0x10000 },
    		{ getAddonSetting("radio2genre18") == "true", 0x20000 }, 
			{ getAddonSetting("radio2genre19") == "true", 0x40000 },
    		{ getAddonSetting("radio2genre20") == "true", 0x80000 },
    		{ getAddonSetting("radio2genre21") == "true", 0x100000 },
    		{ getAddonSetting("radio2genre22") == "true", 0x200000 },
    		{ getAddonSetting("radio2genre23") == "true", 0x400000 },
    		{ getAddonSetting("radio2genre24") == "true", 0x800000 },
    		{ getAddonSetting("radio2genre25") == "true", 0x1000000 },
    		{ getAddonSetting("radio2genre26") == "true", 0x2000000 },
    		{ getAddonSetting("radio2genre27") == "true", 0x4000000 }, };
    int mask = 0;
    for (int i = 0; i < sizeof(radiogenres) / sizeof(radiogenres[0]); i++)
      if (radiogenres[i].enable) mask |= radiogenres[i].id;

    return (sp_radio_genre) mask;
  }

  CStdString Settings::getAddonSetting(CStdString key) {
    ADDON::AddonPtr addon;
    const CStdString pluginId = "plugin.music.spotyXBMC";
    CStdString value = "";

    if (ADDON::CAddonMgr::Get().GetAddon(pluginId, addon)) {
      ADDON::CAddonMgr::Get().LoadAddonDescription(pluginId, addon);

      value = addon->GetSetting(key);
    }
    return value;
  }

  CStdString Settings::getAddonString(int id) {
    ADDON::AddonPtr addon;
    const CStdString pluginId = "plugin.music.spotyXBMC";
    CStdString value = "";

    if (ADDON::CAddonMgr::Get().GetAddon(pluginId, addon)) {

      value = addon->GetString(id);
    }
    return value;
  }

} /* namespace addon_music_spotify */
