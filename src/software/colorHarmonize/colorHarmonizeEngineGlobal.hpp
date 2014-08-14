
// Copyright (c) 2013, 2014 openMVG authors.

// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef OPENMVG_COLOR_HARMONIZATION_ENGINE_GLOBAL_H
#define OPENMVG_COLOR_HARMONIZATION_ENGINE_GLOBAL_H

#include <openMVG/numeric/numeric.h>
#include <software/SfM/SfMEngine.hpp>
#include <openMVG/features/features.hpp>
#include <openMVG/tracks/tracks.hpp>

#include <memory>

namespace openMVG{

class ColorHarmonizationEngineGlobal : public ReconstructionEngine
{
public:
  ColorHarmonizationEngineGlobal( const std::string & sImagePath,
                            const std::string & sMatchesPath,
                            const std::string & sMatchesFile,
                            const std::string & sOutDirectory,
                            const int selectionMethod = -1,
                            const int imgRef = -1);

  ~ColorHarmonizationEngineGlobal();

  virtual bool Process();

private:

  bool CleanGraph();

  /// Read input data (point correspondences)
  bool ReadInputData();

public:

  const std::vector< std::string > & getFilenamesVector() const { return _vec_fileNames; }

  const std::vector< std::pair< size_t, size_t > > & getImagesSize() const { return _vec_imageSize; }

private:

  int _selectionMethod;
  int _imgRef;
  std::string _sMatchesFile;

  // -----
  // Input data
  // ----

  std::vector< std::string > _vec_fileNames; // considered images
  std::map< size_t, std::vector< SIOPointFeature > > _map_feats; // feature per images

  std::vector< std::pair< size_t, size_t > > _vec_imageSize; // Size of each image

  openMVG::matching::PairWiseMatches _map_Matches; // pairwise geometric matches
};


} // namespace openMVG

#endif // OPENMVG_COLOR_HARMONIZATION_ENGINE_GLOBAL_H
