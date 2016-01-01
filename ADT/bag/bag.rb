class Bag
  def initialize
    @payload = [];
  end

  def add item
    @payload.push item
  end

  def is_empty?
    @payload.empty?
  end

  def size
    @payload.size
  end
end
