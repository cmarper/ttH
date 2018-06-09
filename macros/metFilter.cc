unsigned int bitmask_filter_data_ = 511;  // 0b111111111
unsigned int bitmask_filter_mc_ = 509; // 0b111111101

bool pass_met_filters(unsigned int filterBits, bool _isMC)
{
	if (!_isMC) {
		return (filterBits & bitmask_filter_data_) == bitmask_filter_data_;
	}
	else {
		return (filterBits & bitmask_filter_mc_) == bitmask_filter_mc_;
	}
}
