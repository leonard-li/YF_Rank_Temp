
Pod::Spec.new do |spec|

  spec.name         = "YF_Rank_Temp"
  spec.version      = "1.0.1"
  spec.summary      = "排行榜"

  spec.description  = <<-DESC
  iOS排行榜功能库
                   DESC

  spec.homepage     = "https://github.com/leonard-li/YF_Rank_Temp.git"


  spec.license      = { :type => "MIT", :file => "LICENSE" }

  spec.author             = { "leonard.li" => "495145872@qq.com" }

  spec.ios.deployment_target = "9.0"

  spec.source       = { :git => "https://github.com/leonard-li/YF_Rank_Temp.git", :tag => spec.version }

  spec.vendored_frameworks = 'YFRanking.framework'

  spec.requires_arc = true

  spec.dependency "YF_Auth", '>= 2.0.0'

end
