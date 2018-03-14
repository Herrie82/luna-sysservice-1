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


#ifndef BUILDINFOHANDLER_H
#define BUILDINFOHANDLER_H

#include "PrefsHandler.h"
#include <map>
#include <string>
#include <list>
#include <pbnjson.hpp>
#include <luna-service2/lunaservice.h>

class BuildInfoHandler : public PrefsHandler
{
public:

	BuildInfoHandler(LSHandle* serviceHandle);
	virtual ~BuildInfoHandler();

	virtual std::list<std::string> keys() const;
	virtual bool validate(const std::string& key, const pbnjson::JValue &value);
	virtual void valueChanged(const std::string& key, const pbnjson::JValue &value);
	virtual pbnjson::JValue valuesForKey(const std::string& key);

private:

	void init();
	static int readBuildInfoFile(std::map<std::string,std::string>& KVpairs);
	
	static std::list<std::string> s_keys;			//leave empty, but allocated so that keys() doesn't keep making new empty lists
};	

#endif /* BUILDINFOHANDLER_H */
