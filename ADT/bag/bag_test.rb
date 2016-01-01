require './bag'
require "test/unit"

class BagTest < Test::Unit::TestCase
  def test_bag
    bag = Bag.new
    assert bag.is_empty?

    item = 'happy new year'
    bag.add item
    assert_not bag.is_empty?

    assert_equal 1, bag.size
  end
end
