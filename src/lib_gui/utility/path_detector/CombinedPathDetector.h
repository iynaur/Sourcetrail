#ifndef COMBINED_PATH_DETECTOR_H
#define COMBINED_PATH_DETECTOR_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "utility/path_detector/PathDetector.h"

class CombinedPathDetector: public PathDetector
{
public:
	CombinedPathDetector();
    virtual ~CombinedPathDetector();

	void addDetector(std::shared_ptr<PathDetector> detector);

    std::vector<std::string> getWorkingDetectorNames();

	virtual std::vector<FilePath> getPaths() const;
	std::vector<FilePath> getPaths(std::string detectorName) const;

private:
	typedef std::map<std::string, std::shared_ptr<PathDetector>> DetectorMap;
	typedef std::pair<std::string, std::shared_ptr<PathDetector>> DetectorPair;

	DetectorMap m_detectors;
};

#endif // COMBINED_PATH_DETECTOR_H