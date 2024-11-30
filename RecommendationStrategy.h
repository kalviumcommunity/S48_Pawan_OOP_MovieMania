class RecommendationStrategy {
public:
    virtual void showRecommendations() const = 0;
    virtual ~RecommendationStrategy() = default;
};
