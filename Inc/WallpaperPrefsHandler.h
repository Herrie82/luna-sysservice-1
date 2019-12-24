// Copyright (c) 2010-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0


#ifndef WALLPAPERPREFSHANDLER_H
#define WALLPAPERPREFSHANDLER_H

#include "PrefsHandler.h"

#include <QtGui/QImage>

class WallpaperPrefsHandler : public PrefsHandler {
private:
        void init();
public:

	WallpaperPrefsHandler(LSHandle* serviceHandle);
	virtual ~WallpaperPrefsHandler();

	virtual std::list<std::string> keys() const;
	virtual bool validate(const std::string& key, const pbnjson::JValue &value);
	virtual void valueChanged(const std::string& key, const pbnjson::JValue &value);
	virtual bool validate(const std::string& key, const pbnjson::JValue &value, const std::string& originId);
	virtual pbnjson::JValue valuesForKey(const std::string& key);

	virtual bool isPrefConsistent();
	virtual void restoreToDefault();

	bool importWallpaperViaImage2(const std::string& imageSourceUrl, double centerX,
								  double centerY, double scaleFactor);

	bool importWallpaper(std::string& ret_wallpaperName,const std::string& sourcePathAndFile,
							bool toScreenSize,
							double centerX,double centerY,double scale,std::string& errorText);

	bool importWallpaper(std::string& ret_wallpaperName,const std::string& sourcePath,const std::string& sourceFile,
							bool toScreenSize,
							double centerX,double centerY,double scale,std::string& errorText);

	bool importWallpaper_lowMem(std::string& ret_wallpaperName,
						const std::string& sourcePath,
						const std::string& sourceFile,
						bool toScreenSize,
						double centerX,
						double centerY,
						double scale,
						std::string& errorText);

	bool deleteWallpaper(std::string wallpaperName);

	bool convertImage(const std::string& pathToSourceFile,
					  const std::string& pathToDestFile, const char* format,
					  bool justConvert,
					  double centerX, double centerY, double scale,
					  std::string& r_errorText);

	const std::list<std::string>& scanForWallpapers(bool rebuild=false);
	const std::list<std::string>& buildIndexFromExisting(int * nInvalid=NULL);

	static bool makeLocalUrlsFromWallpaperName(std::string& wallpaperUrl,std::string& wallpaperThumbUrl,const std::string& wallpaperName);
	static bool makeLocalPathnamesFromWallpaperName(std::string& wallpaperUrl,std::string& wallpaperThumbUrl,const std::string& wallpaperName);

	bool getWallpaperSpecFromName(const std::string& wallpaperName,std::string& wallpaperFile,std::string& wallpaperThumbFile);
	bool getWallpaperSpecFromFilename(std::string& wallpaperName,std::string& wallpaperFile,std::string& wallpaperThumbFile);

private:
	QImage clipImageToScreenSizeWithFocus(QImage& image, int focus_x,int focus_y);
	QImage clipImageToScreenSize(QImage& image, bool center);
	int resizeImage(const std::string& sourceFile, const std::string& destFile, int destImgW, int destImgH, const char* format);
	void getScreenDimensions();

	std::list<std::string> m_wallpapers;
	std::list<std::string> m_thumbnails;
	std::string m_currentWallpaperName;
	static std::string s_wallpaperDir;
	static std::string s_wallpaperThumbsDir;

};

#endif
