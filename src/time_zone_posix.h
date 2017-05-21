// Copyright 2016 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

// Parsing of a POSIX zone spec as described in the TZ part of section 8.3 in
// http://pubs.opengroup.org/onlinepubs/009695399/basedefs/xbd_chap08.html.
//
// The current POSIX spec for America/Los_Angeles is "PST8PDT,M3.2.0,M11.1.0",
// which would be broken down as ...
//
//   PosixTimeZone {
//     std_abbr = "PST"
//     std_offset = -28800
//     dst_abbr = "PDT"
//     dst_offset = -25200
//     dst_start = PosixTransition {
//       date {
//         m {
//           month = 3
//           week = 2
//           weekday = 0
//         }
//       }
//       time {
//         offset = 7200
//       }
//     }
//     dst_end = PosixTransition {
//       date {
//         m {
//           month = 11
//           week = 1
//           weekday = 0
//         }
//       }
//       time {
//         offset = 7200
//       }
//     }
//   }

#ifndef CCTZ_TIME_ZONE_POSIX_H_
#define CCTZ_TIME_ZONE_POSIX_H_

#include <cstdint>
#include <string>

#include "time_zone.h"

namespace cctz {

// Breaks down a POSIX time-zone specification into its constituent pieces,
// filling in any missing values (DST offset, or start/end transition times)
// with the standard-defined defaults. Returns false if the specification
// could not be parsed (although some fields of *res may have been altered).
bool ParsePosixSpec(const std::string& spec, PosixTimeZone* res);

std::string PosixTimeZoneToName(const PosixTimeZone& spec);
bool PosixTimeZoneFromName(const std::string& name, PosixTimeZone* spec);

}  // namespace cctz

#endif  // CCTZ_TIME_ZONE_POSIX_H_
